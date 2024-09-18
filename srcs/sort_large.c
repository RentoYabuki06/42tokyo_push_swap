/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:51:01 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/18 18:34:50 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void copy_stack_to_array(t_stack *stack, int size, int *array)
{
    t_node *current = stack->top;
    int i = 0;
    while (i < size && current)
    {
        array[i] = current->value;
        current = current->next;
        i++;
    }
}

// 配列をクイックソートする関数
static void quicksort_array(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = array[high];
        int i = low - 1;
        int j, temp;

        for (j = low; j < high; j++)
        {
            if (array[j] <= pivot)
            {
                i++;
                // swap array[i] and array[j]
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // swap array[i+1] and array[high]
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;

        quicksort_array(array, low, pi - 1);
        quicksort_array(array, pi + 1, high);
    }
}

// ピボット値を取得する関数
static int get_pivot_value(t_stack *stack, int size)
{
    int *array;
    int pivot;
    int middle;

    array = (int *)malloc(sizeof(int) * size);
    if (!array)
    {
        // メモリ確保に失敗した場合のエラー処理
        exit(EXIT_FAILURE);
    }

    // スタックの値を配列にコピー
    copy_stack_to_array(stack, size, array);

    // 配列をソート
    quicksort_array(array, 0, size - 1);

    // 中央値を取得
    middle = size / 2;
    pivot = array[middle];

    free(array);
    return pivot;
}


static void ft_quicksort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (size <= 1 || stack_a == NULL || *stack_a == NULL)
        return;

    int pivot = get_pivot_value(*stack_a, size);
    int i = 0;
    int pushed = 0;

    // パーティションフェーズ
    while (i < size)
    {
        if ((*stack_a)->top->value < pivot)
        {
            ft_pb(stack_a, stack_b); // ピボット未満の要素をstack_bにプッシュ
            pushed++;
        }
        else
        {
            ft_ra(stack_a); // ピボット以上の要素を後方に回転
        }
        i++;
    }

    // 再帰的にソート（ピボット未満の部分）
    ft_quicksort_stack(stack_b, stack_a, pushed);

    // stack_bから要素を戻す
    while (pushed--)
    {
        ft_pa(stack_a, stack_b);
    }

    // ピボット以上の部分のサイズを計算
    int sorted_size = size - pushed;

    // 再帰的にソート（ピボット以上の部分）
    ft_quicksort_stack(stack_a, stack_b, sorted_size);
}

// ソートを開始する関数
void ft_sort_large(t_stack **stack_a, t_stack **stack_b)
{
    int size = (*stack_a)->size;
    ft_quicksort_stack(stack_a, stack_b, size);

    // メモリの解放
    free(stack_b);
}
