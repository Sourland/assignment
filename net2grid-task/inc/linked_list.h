#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "stdint.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "print.h"
#include "change.h"

/**
 * @brief Enumeration of supported data types for linked list nodes.
 *
 * This enum defines the different types of data that can be stored in a node of the linked list.
 */
typedef enum {
    UINT8,   /**< Unsigned 8-bit integer */
    INT8,    /**< Signed 8-bit integer */
    UINT16,  /**< Unsigned 16-bit integer */
    INT16,   /**< Signed 16-bit integer */
    UINT32,  /**< Unsigned 32-bit integer */
    INT32,   /**< Signed 32-bit integer */
    UINT64,  /**< Unsigned 64-bit integer */
    INT64,   /**< Signed 64-bit integer */
    CHAR,    /**< Character (char) */
    FLOAT,   /**< Single-precision floating point */
    DOUBLE,  /**< Double-precision floating point */
} DataType;

/**
 * @brief Defines a node for the linked list.
 *
 * A linked list node contains data of a specific type and a pointer to the next node in the list.
 */
typedef struct list_node {
    void * data;              /**< Pointer to the data in the node */
    DataType data_type;       /**< The type of data stored in the node (from the DataType enum) */
    struct list_node * next_node; /**< Pointer to the next node in the list */
} list_node_t;

/**
 * @brief Initializes a new node with data and a specified type.
 *
 * This function allocates memory for a new node and initializes it with the provided data and data type.
 *
 * @param node A reference to the head of the list to initialize.
 * @param data A pointer to the data of any data type to store in the node.
 * @param data_type The type of the data, specified by the DataType enum.
 */
void initialize_node(list_node_t ** node, void * data, DataType data_type);

/**
 * @brief Prints all nodes in the linked list.
 *
 * This function traverses the linked list and prints each node's data using the appropriate print function
 * based on its data type. If the data type is invalid, an error message is displayed.
 *
 * @param list_head The head node of the linked list.
 */
void print_list(list_node_t * list_head);

/**
 * @brief Pushes a new node to the front of the linked list.
 *
 * This function adds a new node to the front (head) of the list, making it the first node.
 *
 * @param list_head A reference to the head node of the linked list.
 * @param node The node to push to the front of the list.
 */
void push_node(list_node_t ** list_head, list_node_t * node);

/**
 * @brief Adds a new node at the end of the linked list.
 *
 * This function traverses the list to find the last node and adds the new node after it.
 *
 * @param list_head A pointer to the head node of the linked list.
 * @param node The node to add at the end of the list.
 */
void add_node_at_end(list_node_t ** list_head, list_node_t * node);

/**
 * @brief Pops the first node from the linked list.
 *
 * This function removes the first node from the list and returns its data. The memory for the node is freed.
 *
 * @param list_head A pointer to the head node of the linked list.
 * @return A pointer to the data of the removed node.
 */
void * pop_first_node(list_node_t ** list_head);

/**
 * @brief Deletes the last node in the linked list.
 *
 * This function removes the last node from the list and returns its data. The memory for the node is freed.
 *
 * @param list_head A pointer to the head node of the linked list.
 * @return A pointer to the data of the deleted node.
 */
void * delete_last_node(list_node_t ** list_head);

/**
 * @brief Searches the linked list for a node containing the specified value.
 *
 * This function traverses the list, comparing the data of each node with the given value based on the data type.
 *
 * @param list_head The head node of the linked list.
 * @param value A pointer to the value to search for.
 * @param data_type The type of the data to search for, as specified by the DataType enum.
 * @return The index of the node containing the value, or -1 if not found.
 */
int search_list(list_node_t * list_head, void * value, DataType data_type);

/**
 * @brief Adds a new node to a specific position in the linked list.
 *
 * This function inserts a new node at the given position in the list. If the position is 0, the node is added
 * at the front. If the position exceeds the length of the list, the node is not added.
 *
 * @param list_head A pointer to the head node of the linked list.
 * @param node The node to add at the specified position.
 * @param position The position where the new node should be inserted (starting from 0).
 */
void add_node_to_position(list_node_t ** list_head, list_node_t * node, uint16_t position);

/**
 * @brief Deletes a node at a specific position in the linked list.
 *
 * This function removes the node at the given position from the list and returns its data. The memory for the
 * node is freed.
 *
 * @param list_head A pointer to the head node of the linked list.
 * @param position The position of the node to delete (starting from 0).
 * @return A pointer to the data of the deleted node.
 */
void * delete_node_of_position(list_node_t ** list_head, uint16_t position);

/**
 * @brief Searches for and deletes a node containing the specified value.
 *
 * This function searches the list for a node containing the specified value and deletes it. The memory for the
 * node is freed, and the data is returned.
 *
 * @param list_head A pointer to the head node of the linked list.
 * @param value A pointer to the value to search for and delete.
 * @param data_type The type of the data to search for, as specified by the DataType enum.
 * @return A pointer to the data of the deleted node, or NULL if the node was not found.
 */
void * search_and_delete_node(list_node_t ** list_head, void * value, DataType data_type);

/**
 * @brief Changes the value of a node at a specific index in the linked list.
 *
 * This function changes the data stored in a node at the given index to the new value, based on the node's
 * data type.
 *
 * @param list_head A pointer to the head node of the linked list.
 * @param index The index of the node whose value is to be changed.
 * @param new_value A pointer to the new value to assign to the node.
 * @param data_type The type of the data to store in the node, as specified by the DataType enum.
 */
void change_node_value(list_node_t **list_head, uint16_t index, void *new_value, DataType data_type);

#endif
