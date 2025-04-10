#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

void test_initialize_node() {
    list_node_t *node = NULL;
    uint8_t value_uint8 = 10;
    initialize_node(&node, &value_uint8, UINT8);
    assert(node != NULL && *(uint8_t*)node->data == 10);
    free(node->data);
    free(node);

    int8_t value_int8 = -5;
    initialize_node(&node, &value_int8, INT8);
    assert(node != NULL && *(int8_t*)node->data == -5);
    free(node->data);
    free(node);

    // Repeat similar tests for other data types like UINT16, INT16, etc.
}


void test_push_node() {
    list_node_t *list_head = NULL;

    // Initialize and push the first node
    uint8_t value1 = 10;
    list_node_t *node1 = NULL;
    initialize_node(&node1, &value1, UINT8);
    push_node(&list_head, node1);

    // Initialize and push the second node
    uint8_t value2 = 20;
    list_node_t *node2 = NULL;
    initialize_node(&node2, &value2, UINT8);
    push_node(&list_head, node2);

    // Verify that the head contains node2, the last pushed node
    assert(*(uint8_t*)list_head->data == 20);

    // Verify that node2's next node points to node1
    assert(*(uint8_t*)list_head->next_node->data == 10);

    // Cleanup by freeing the nodes in the list
    list_node_t *current = list_head;
    while (current != NULL) {
        list_node_t *temp = current;
        current = current->next_node;
        free(temp->data);  // Free the data of the current node
        free(temp);        // Free the node itself
    }
}


void test_add_node_at_end() {
    list_node_t *list_head = NULL;

    // Initialize and push the first node
    uint8_t value1 = 10;
    list_node_t *node1 = NULL;
    initialize_node(&node1, &value1, UINT8);
    push_node(&list_head, node1);

    // Initialize and add the second node at the end
    uint8_t value2 = 20;
    list_node_t *node2 = NULL;
    initialize_node(&node2, &value2, UINT8);
    add_node_at_end(&list_head, node2);

    // Verify that the second node is at the end of the list
    assert(*(uint8_t*)list_head->next_node->data == 20);
    assert(list_head->next_node->next_node == NULL);

    // Cleanup by freeing all nodes in the list
    list_node_t *current = list_head;
    while (current != NULL) {
        list_node_t *temp = current;
        current = current->next_node;
        free(temp->data);  // Free the data of the current node
        free(temp);        // Free the node itself
    }
}


void test_pop_first_node() {
    list_node_t *list_head = NULL;

    uint8_t value1 = 10;
    list_node_t *node1 = NULL;
    initialize_node(&node1, &value1, UINT8);
    push_node(&list_head, node1);

    uint8_t value2 = 20;
    list_node_t *node2 = NULL;
    initialize_node(&node2, &value2, UINT8);
    push_node(&list_head, node2);  // node2 is now at the head

    // Pop first node (node2)
    void *data = pop_first_node(&list_head);
    assert(data != NULL && *(uint8_t*)data == 20);
    free(data);

    // Now node1 should be the head
    assert(*(uint8_t*)list_head->data == 10);

    // Cleanup
    free(list_head->data);
    free(list_head);
}


void test_delete_last_node() {
    list_node_t *list_head = NULL;

    uint8_t value1 = 10;
    list_node_t *node1 = NULL;
    initialize_node(&node1, &value1, UINT8);
    push_node(&list_head, node1);

    uint8_t value2 = 20;
    list_node_t *node2 = NULL;
    initialize_node(&node2, &value2, UINT8);
    push_node(&list_head, node2);

    // Delete last node (node1)
    void *data = delete_last_node(&list_head);
    assert(data != NULL && *(uint8_t*)data == 10);
    free(data);

    // Verify that now node2 is the only node left
    assert(*(uint8_t*)list_head->data == 20);

    // Cleanup
    free(list_head->data);
    free(list_head);
}


void test_search_and_delete_node() {
    list_node_t *list_head = NULL;

    uint8_t value1 = 10;
    list_node_t *node1 = NULL;
    initialize_node(&node1, &value1, UINT8);
    push_node(&list_head, node1);

    uint8_t value2 = 20;
    list_node_t *node2 = NULL;
    initialize_node(&node2, &value2, UINT8);
    push_node(&list_head, node2);

    // Search and delete node with value 10
    uint8_t search_value = 10;
    void *data = search_and_delete_node(&list_head, &search_value, UINT8);
    assert(data != NULL && *(uint8_t*)data == 10);
    free(data);

    // Verify that only node2 is left
    assert(*(uint8_t*)list_head->data == 20);

    // Cleanup
    free(list_head->data);
    free(list_head);
}


void test_change_node_value() {
    list_node_t *list_head = NULL;

    uint8_t value1 = 10;
    list_node_t *node1 = NULL;
    initialize_node(&node1, &value1, UINT8);
    push_node(&list_head, node1);

    uint8_t value2 = 20;
    list_node_t *node2 = NULL;
    initialize_node(&node2, &value2, UINT8);
    push_node(&list_head, node2);  // node2 is now the head

    // Change value of node at index 0 (node2)
    uint8_t new_value = 99;
    change_node_value(&list_head, 0, &new_value, UINT8);
    assert(*(uint8_t*)list_head->data == 99);

    // Cleanup
    free(list_head->next_node->data);
    free(list_head->next_node);
    free(list_head->data);
    free(list_head);
}


void test_empty_list_operations() {
    list_node_t *list_head = NULL;

    // Test pop on an empty list
    void *data = pop_first_node(&list_head);
    assert(data == NULL);

    // Test delete last on an empty list
    data = delete_last_node(&list_head);
    assert(data == NULL);

    // Test search on an empty list
    uint8_t search_value = 10;
    int index = search_list(list_head, &search_value, UINT8);
    assert(index == -1);

    // Test delete node by position on an empty list
    data = delete_node_of_position(&list_head, 0);
    assert(data == NULL);
}


void test_change_node_value_invalid_index() {
    list_node_t *list_head = NULL;

    // Insert one node
    uint8_t value = 42;
    list_node_t *node = NULL;
    initialize_node(&node, &value, UINT8);
    push_node(&list_head, node);

    // Try to change a node value at invalid index (e.g., 5)
    uint8_t new_value = 99;
    change_node_value(&list_head, 5, &new_value, UINT8);

    // Original value should remain unchanged
    assert(*(uint8_t*)list_head->data == 42);

    // Cleanup
    free(list_head->data);
    free(list_head);
}


void test_delete_node_of_position_invalid() {
    list_node_t *list_head = NULL;

    // Insert two nodes
    uint8_t val1 = 11, val2 = 22;
    list_node_t *node1 = NULL, *node2 = NULL;
    initialize_node(&node1, &val1, UINT8);
    initialize_node(&node2, &val2, UINT8);
    push_node(&list_head, node1);
    push_node(&list_head, node2); // node2 is head

    // Try deleting at out-of-bounds index
    void *data = delete_node_of_position(&list_head, 5);
    assert(data == NULL);

    // Try deleting at a negative index (if function handles signed int)
    data = delete_node_of_position(&list_head, -1);
    assert(data == NULL);

    // Cleanup remaining nodes
    list_node_t *current = list_head;
    while (current) {
        list_node_t *tmp = current;
        current = current->next_node;
        free(tmp->data);
        free(tmp);
    }
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_initialize_node),
        cmocka_unit_test(test_push_node),
        cmocka_unit_test(test_add_node_at_end),
        cmocka_unit_test(test_pop_first_node),
        cmocka_unit_test(test_delete_last_node),
        cmocka_unit_test(test_search_and_delete_node),
        cmocka_unit_test(test_change_node_value),
        cmocka_unit_test(test_empty_list_operations),
        cmocka_unit_test(test_change_node_value_invalid_index),
        cmocka_unit_test(test_delete_node_of_position_invalid),

    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
