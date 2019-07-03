#include <stdio.h>

#include <locale.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  Primer input.txt :
+ s 3 3
+ s 2 2
+ s 2 3
+ v 1 2 -5
+ v 1 4 4
*/
struct element
{
    char *task;
    struct element *next;
};

typedef struct element LIST;

void freeList(struct element* head);
void convert_vector_to_str_vector(int size, int *vector_1, int *vector_2, float *vector_result, char *vector_1_str, char *vector_2_str, char *vector_result_str);

void freeList(LIST *head)
{
    LIST *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

}

void add_to_list(LIST *head, LIST *current, char *line)
{
    LIST *node = malloc(sizeof(LIST));
    node->task = strdup(line);
    node->next = NULL;

    if (head == NULL)
    {
        current = head = node;
    }
    else
    {
        current = current->next = node;
    }
}


void convert_vector_to_str_vector(int size, int *vector_1, int *vector_2, float *vector_result, char *vector_1_str, char *vector_2_str, char *vector_result_str)
{

    int cur_pos=0;
    int i=0;
    memset(vector_1_str, 0, 255);
    memset(vector_2_str, 0, 255);
    memset(vector_result_str, 0, 255);


    for (i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cur_pos += sprintf(&vector_1_str[cur_pos], "%d ", vector_1[i]);
        }
        else
        {
            cur_pos += sprintf(&vector_1_str[cur_pos], "%d", vector_1[i]);
        }
    }
    cur_pos=0;

    for (i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cur_pos += sprintf(&vector_2_str[cur_pos], "%d ", vector_2[i]);
        }
        else
        {
            cur_pos += sprintf(&vector_2_str[cur_pos], "%d", vector_2[i]);
        }
    }

    cur_pos=0;


    for (i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cur_pos += sprintf(&vector_result_str[cur_pos], "%.2f ", vector_result[i]);
        }
        else
        {
            cur_pos += sprintf(&vector_result_str[cur_pos], "%.2f)", vector_result[i]);
        }
    }
    printf("\n");
}


int main(void)
{
    char line[128];
    LIST *in_current, *in_head;
    LIST *out_current, *out_head;
    char operation_type = 0;
    char data_type = 0;
    int i = 0;

    FILE *in_file;
    FILE *out_file;

    setlocale(LC_ALL, "Russian");

    in_head = in_current = NULL;
    out_head = out_current = NULL;
    in_file = fopen("input.txt", "r");
    out_file = fopen("output.txt", "w");
    memset(line, 0, sizeof(line));

    while (fgets(line, sizeof(line), in_file))
    {


        LIST *in_node = malloc(sizeof(LIST));
        in_node->task = strdup(line);
        in_node->next = NULL;

        if (in_head == NULL)
        {
            in_current = in_head = in_node;
        }
        else
        {
            in_current = in_current->next = in_node;
        }

    }
    fclose(in_file);

    for (in_current = in_head; in_current; in_current = in_current->next)
    {
        printf("Current task: %s\n", in_current->task);
        LIST *out_node = malloc(sizeof(LIST));

        sscanf(in_current->task, "%c %c", &operation_type, &data_type);

        printf("operation_type= %c\n", operation_type);
        printf("data_type= %c\n", data_type);

        switch (data_type)

        {
            case 's':
            {
                int number_1;
                int number_2;
                float result;

                sscanf(&in_current->task[0] + 4, "%d %d", &number_1, &number_2);

                switch (operation_type)
                {
                    case '+':
                        result = number_1 + number_2;

                        memset(line, 0, sizeof(line));
                        sprintf(line, "Otvet: %d + %d = %f \n", number_1, number_2,
                                result);

                        out_node->task = strdup(line);
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }
                        break;
                    case '-':
                        result = number_1 - number_2;
                        memset(line, 0, sizeof(line));
                        sprintf(line, "Otvet: %d - %d = %f \n", number_1, number_2,
                                result);

                        out_node->task = strdup(line);
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '*':
                        result = number_1 * number_2;
                        memset(line, 0, sizeof(line));
                        sprintf(line, "Otvet: %d * %d = %f \n", number_1, number_2,
                                result);

                        out_node->task = strdup(line);
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '/':
                        result = number_1 / number_2;
                        memset(line, 0, sizeof(line));
                        sprintf(line, "Otvet: %d / %d = %f \n", number_1, number_2,
                                result);

                        out_node->task = strdup(line);
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '^':
                        result = 1;

                        for (i = 0; i < number_2; i++)
                        {
                            result = result * number_1;
                        }
                        memset(line, 0, sizeof(line));
                        sprintf(line, "Otvet: %d ^ %d = %f \n", number_1, number_2,
                                result);

                        out_node->task = strdup(line);
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }
                        break;
                    case '!':
                        if (number_1 == 0)
                        {
                            result = 1;
                        }
                        else
                        {
                            result = 1;
                            for (i = 1; i <= number_1; i++)
                            {
                                result = result * i;
                            }
                        }
                        memset(line, 0, sizeof(line));
                        sprintf(line, "Otvet: %d! = %f \n", number_1, result);

                        out_node->task = strdup(line);
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    default:
                        puts(
                                "Oshibka, proverte file");
                        break;
                }
                break;
            }
            case 'v':
            {
                int *vector_1;
                int *vector_2;
                float *vector_result;
                char *vector_1_str;
                char *vector_2_str;
                char *vector_result_str;
                int size = 0;

                sscanf(&in_current->task[0] + 4, "%d", &size);

                vector_1 = calloc(size, sizeof(int));
                vector_2 = calloc(size, sizeof(int));
                vector_result = calloc(size, sizeof(float));
                vector_1_str = calloc(255, sizeof(char));
                vector_2_str = calloc(255, sizeof(char));
                vector_result_str = calloc(255, sizeof(char));

                for (i = 0; i < size; i++)
                {
                    sscanf(&in_current->task[0] + 6, "%d ", &vector_1[i]);
                }

                for (i = 0; i < size; i++)
                {
                    printf("vector_1[%d] = %d ", i, vector_1[i]);
                }
                printf("\n");

                for (i = 0; i < size; i++)
                {
                    sscanf(&in_current->task[0] + 6+size+1, "%d ", &vector_2[i]);
                }

                for (i = 0; i < size; i++)
                {
                    printf("vector_2[%d] = %d ", i, vector_2[i]);
                }
                printf("\n");

                switch (operation_type)
                {
                    case '+':

                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] + vector_2[i];
                        }

                        convert_vector_to_str_vector(size,vector_1,vector_2,vector_result,vector_1_str,vector_2_str,vector_result_str);

                        memset(line, 0, sizeof(line));
                        sprintf(line, "(%s) + (%s) = (%s) \n", vector_1_str, vector_2_str, vector_result_str);
                        LIST *out_node = malloc(sizeof(LIST));
                        out_node->task = strdup(line);
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '-':

                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] - vector_2[i];
                        }

                        convert_vector_to_str_vector(size,vector_1,vector_2,vector_result,vector_1_str,vector_2_str,vector_result_str);

                        memset(line, 0, sizeof(line));
                        sprintf(line, "(%s) + (%s) = (%s) \n", vector_1_str, vector_2_str, vector_result_str);
                        out_node->task = strdup(line);
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '*':

                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] * vector_2[i];
                        }

                        convert_vector_to_str_vector(size,vector_1,vector_2,vector_result,vector_1_str,vector_2_str,vector_result_str);

                        memset(line, 0, sizeof(line));
                        sprintf(line, "(%s) + (%s) = (%s) \n", vector_1_str, vector_2_str, vector_result_str);

                        out_node->task = strdup(line);
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '/':

                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] / vector_2[i];
                        }

                        convert_vector_to_str_vector(size,vector_1,vector_2,vector_result,vector_1_str,vector_2_str,vector_result_str);

                        memset(line, 0, sizeof(line));
                        sprintf(line, "(%s) + (%s) = (%s) \n", vector_1_str, vector_2_str, vector_result_str);

                        out_node->task = strdup(line);
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    default:
                        puts(
                                "Oshibka, proverte file");
                        break;
                }

                free(vector_1);
                free(vector_2);
                free(vector_result);
                free(vector_1_str);
                free(vector_2_str);
                free(vector_result_str);

                break;
            }
            default:
                puts("Oshibka, proverte file");
                break;
        }

    }

    for (out_current = out_head; out_current; out_current = out_current->next)
    {
        fprintf(out_file, "%s", out_current->task);
    }
    fclose(out_file);
    freeList(in_head);
    freeList(out_head);
    return 0;
}