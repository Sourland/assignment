#include "linked_list.h"

void print_list(list_node_t *list_head) {
    list_node_t *current = list_head;
    while (current != NULL) {
        if (current->data_type < 0 || current->data_type >= NUM_PRINT_FUNCTIONS) {
        } else {
            print_functions[current->data_type](current->data);
        }
        current = current->next_node;
    }
}



void* allocate_data(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        return NULL;
    }
    return ptr;
}

void initialize_node(list_node_t **node, void *data, DataType data_type) {
    if (node == NULL || data == NULL) {
        return;
    }

    *node = (list_node_t *)malloc(sizeof(list_node_t));
    if (*node == NULL) {
        return;
    }

    (*node)->data_type = data_type;

    switch (data_type) {
        case UINT8:
            (*node)->data = allocate_data(sizeof(uint8_t));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(uint8_t));
            break;
        case INT8:
            (*node)->data = allocate_data(sizeof(int8_t));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(int8_t));
            break;
        case UINT16:
            (*node)->data = allocate_data(sizeof(uint16_t));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(uint16_t));
            break;
        case INT16:
            (*node)->data = allocate_data(sizeof(int16_t));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(int16_t));
            break;
        case UINT32:
            (*node)->data = allocate_data(sizeof(uint32_t));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(uint32_t));
            break;
        case INT32:
            (*node)->data = allocate_data(sizeof(int32_t));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(int32_t));
            break;
        case UINT64:
            (*node)->data = allocate_data(sizeof(uint64_t));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(uint64_t));
            break;
        case INT64:
            (*node)->data = allocate_data(sizeof(int64_t));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(int64_t));
            break;
        case FLOAT:
            (*node)->data = allocate_data(sizeof(float));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(float));
            break;
        case DOUBLE:
            (*node)->data = allocate_data(sizeof(double));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(double));
            break;
        case CHAR:
            (*node)->data = allocate_data(sizeof(char));
            if ((*node)->data) memcpy((*node)->data, data, sizeof(char));
            break;
        default:
            free(*node);
            return;
    }

    (*node)->next_node = NULL;
}

void push_node(list_node_t ** list_head, list_node_t * node) {
    if (node == NULL || list_head == NULL) {
        return;
    }

    node->next_node = *list_head;
    *list_head = node;
}

void add_node_at_end(list_node_t ** list_head, list_node_t * node) {
    if (node == NULL) return;

    node->next_node = NULL;

    if (*list_head == NULL) {
        *list_head = node;
        return;
    }

    list_node_t *current = *list_head;
    while (current->next_node != NULL) {
        current = current->next_node;
    }

    current->next_node = node;
}


void * pop_first_node(list_node_t ** list_head) {
    list_node_t * next_node = NULL;

    if (*list_head == NULL) {
        return 0;
    }

    next_node = (*list_head)->next_node;
    void * old_head_data = (*list_head)->data;
    free(*list_head);
    *list_head = next_node;

    return old_head_data;
}

void * delete_last_node(list_node_t **list_head) {
    if (*list_head == NULL) {
        return 0;
    }

    if ((*list_head)->next_node == NULL) {
        void * deleted_node_data = (*list_head)->data;
        free(*list_head);
        *list_head = NULL;
        return deleted_node_data;
    }

    list_node_t *current = *list_head;
    while (current->next_node != NULL && current->next_node->next_node != NULL) {
        current = current->next_node;
    }

    void * deleted_node_data = current->next_node->data;
    free(current->next_node);
    current->next_node = NULL;

    return deleted_node_data;
}

int search_list(list_node_t * list_head, void * value, DataType data_type) {
    if (list_head == NULL) {
        return -1;
    }
    list_node_t * current = list_head;

    uint16_t index = 0;
    while (current != NULL) {
        switch (data_type) {
            case UINT8:
                if (*(uint8_t *)(current->data) == *(uint8_t *)value) {
                    return index;
                }
                break;
            case INT8:
                if (*(int8_t *)(current->data) == *(int8_t *)value) {
                    return index;
                }
                break;
            case UINT16:
                if (*(uint16_t *)(current->data) == *(uint16_t *)value) {
                    return index;
                }
                break;
            case INT16:
                if (*(int16_t *)(current->data) == *(int16_t *)value) {
                    return index;
                }
                break;
            case UINT32:
                if (*(uint32_t *)(current->data) == *(uint32_t *)value) {
                    return index;
                }
                break;
            case INT32:
                if (*(int32_t *)(current->data) == *(int32_t *)value) {
                    return index;
                }
                break;
            case UINT64:
                if (*(uint64_t *)(current->data) == *(uint64_t *)value) {
                    return index;
                }
                break;
            case INT64:
                if (*(int64_t *)(current->data) == *(int64_t *)value) {
                    return index;
                }
                break;
            case FLOAT:
                if (*(float *)(current->data) == *(float *)value) {
                    return index;
                }
                break;
            case DOUBLE:
                if (*(double *)(current->data) == *(double *)value) {
                    return index;
                }
                break;
            case CHAR:
                if (*(char *)(current->data) == *(char *)value) {
                    return index;
                }
                break;
            default:
                printf("Unknown data type\n");
                return -1;
        }

        current = current->next_node;
        index++;
    }
    return -1;
}

void add_node_to_position(list_node_t **list_head, list_node_t *node, uint16_t position) {
    if (node == NULL) return;
    if (*list_head == NULL || position == 0) {
        node->next_node = *list_head;
        *list_head = node;
        return;
    }

    list_node_t *current = *list_head;
    uint16_t current_position = 0;

    while (current != NULL && current_position < position - 1) {
        current = current->next_node;
        current_position++;
    }

    if (current == NULL) {
        return;
    }

    node->next_node = current->next_node;
    current->next_node = node;
}

void * delete_node_of_position(list_node_t ** list_head, uint16_t position) {
    if (*list_head == NULL) {
        return NULL;
    }

    list_node_t *current = *list_head;

    if (position == 0) {
        *list_head = current->next_node;
        free(current);
        return NULL;
    }

    uint16_t current_position = 0;

    while (current != NULL && current_position < position - 1) {
        current = current->next_node;
        current_position++;
    }

    if (current == NULL || current->next_node == NULL) {
        return NULL;
    }

    list_node_t *node_to_delete = current->next_node;
    void * deleted_data = node_to_delete->data;
    current->next_node = node_to_delete->next_node;
    free(node_to_delete);

    return deleted_data;
}

void * search_and_delete_node(list_node_t ** list_head, void * value, DataType data_type) {
    if (*list_head == NULL) {
        return NULL;
    }
    int16_t index = search_list(*list_head, value, data_type);
    if (index == -1) {
        return NULL;
    }
    return delete_node_of_position(list_head, index);
}


void change_node_value(list_node_t **list_head, uint16_t index, void *new_value, DataType data_type) {
    if (*list_head == NULL) {
        return;
    }

    list_node_t *current = *list_head;
    uint16_t current_index = 0;

    while (current != NULL && current_index < index) {
        current = current->next_node;
        current_index++;
    }

    if (current != NULL) {
        change_functions[data_type](current->data, new_value);
    } else {
        return;
    }
}
