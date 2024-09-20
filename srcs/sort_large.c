/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:51:01 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/20 10:23:21 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
                // array[i]とarray[j]を交換
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // array[i+1]とarray[high]を交換
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;

        quicksort_array(array, low, pi - 1);
        quicksort_array(array, pi + 1, high);
    }
}

// ピボット値を取得する関数
static int get_pivot_value(t_stack *stack)
{
    int size = 0;
    t_node *current = stack->top;

    // スタックのサイズを計算
    while (current)
    {
        size++;
        current = current->next;
    }

    if (size == 0)
        return 0; // スタックが空の場合の処理

    int *array = (int *)malloc(sizeof(int) * size);
    if (!array)
    {
        // メモリ確保に失敗した場合のエラー処理
        ft_printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    // スタックの値を配列にコピー
    current = stack->top;
    for (int i = 0; i < size; i++)
    {
        array[i] = current->value;
        current = current->next;
    }

    // 配列をソート
    quicksort_array(array, 0, size - 1);

    // 中央値を取得
    int middle = size / 2;
    int pivot = array[middle];

    // ピボット値をデバッグ出力
    ft_printf("Pivot value selected: %d\n", pivot);

    free(array);
    return pivot;
}

// スタックをクイックソートする関数
void ft_sort_large(t_stack **stack_a, t_stack **stack_b)
{
    int size = (*stack_a)->size;
    if (size <= 1 || stack_a == NULL || *stack_a == NULL || (*stack_a)->top == NULL)
        return;

    int pivot = get_pivot_value(*stack_a);
    int num_pushed = 0;
    int num_rotated = 0;
    int current_size = size;

    // パーティションフェーズ
    while (current_size > 0)
    {
        if ((*stack_a)->top == NULL)
            break;

        // スタック状態をデバッグ出力
        ft_printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>\n");
        ft_printf("Before operation, Stack A: \n");
        ft_print_stack(stack_a); // ここでスタックの内容を表示
        ft_printf("Before operation, Stack B: \n");
        ft_print_stack(stack_b);

        if ((*stack_a)->top->value < pivot)
        {
            ft_pb(stack_a, stack_b); // ピボット未満の要素をstack_bにプッシュ
            num_pushed++;
            ft_printf("Performed: pb (push to stack B)\n");
        }
        else
        {
            ft_ra(stack_a); // ピボット以上の要素を後方に回転
            num_rotated++;
            ft_printf("Performed: ra (rotate stack A)\n");
        }

        // 操作後のスタック状態を出力
        ft_printf("\n\n\n");
        ft_printf("After operation, Stack A: \n");
        ft_print_stack(stack_a);
        ft_printf("After operation, Stack B: \n");
        ft_print_stack(stack_b);

        current_size--;
    }

    // 回転した要素を元に戻す
    while (num_rotated--)
    {
        ft_rra(stack_a);
        ft_printf("Performed: rra (reverse rotate stack A)\n");
    }

    // 再帰的にソート（ピボット以上の部分）
    ft_printf("Recursively sorting the larger part of stack A\n");
    ft_sort_large(stack_a, stack_b);

    // 再帰的にソート（ピボット未満の部分）
    ft_printf("Recursively sorting the smaller part of stack B\n");
    ft_sort_large(stack_b, stack_a);

    // stack_bから要素を戻す
    while ((*stack_b)->size > 0)
    {
        ft_pa(stack_a, stack_b);
        ft_printf("Performed: pa (push from stack B to stack A)\n");
    }

    // スタックの状態を最終出力
    ft_printf("\n\n\n");
    ft_printf("Final state of Stack A: \n");
    ft_print_stack(stack_a);
    ft_printf("Final state of Stack B: \n");
    ft_print_stack(stack_b);
}
