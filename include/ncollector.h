/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncollector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:04:42 by hmouhib           #+#    #+#             */
/*   Updated: 2024/11/30 04:31:30 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCOLLECTOR_H
# define NCOLLECTOR_H

# include <stddef.h>

/**
 * @brief Memory tracking node for NyanCollector 🐱
 *
 * This structure represents a single memory allocation in the NyanCollector.
 * It provides a way to track dynamically allocated memory blocks, storing
 * both the pointer to the data and metadata about the allocation.
 *
 * @param data     Pointer to the dynamically allocated memory block
 *                 This can be of any type (int, char, struct, etc.)
 *
 * @param size     Size of the allocated memory block in bytes
 *                 Useful for understanding memory usage and potential leaks
 *
 * @param next     Pointer to the next memory tracking node
 *                 Allows creation of a linked list of memory allocations
 *
 * @note The memory block pointed to by 'data' is managed by the user
 *       NyanCollector only helps track and free these allocations
 */
typedef struct s_ncollector
{
	void				*data;
	size_t				size;
	struct s_ncollector	*next;
}						t_ncollector;

/**
 * @brief Allocate memory and add to the provided list
 * @param list Pointer to the head of memory tracking list
 * @param size Number of bytes to allocate
 * @return Newly allocated node, or NULL if allocation fails
 */
void					*n_malloc(t_ncollector **list, size_t size);

/**
 * @brief Free all nodes in the list
 * @param list Pointer to the head of memory tracking list
 */
void					n_free(t_ncollector **list);

#endif