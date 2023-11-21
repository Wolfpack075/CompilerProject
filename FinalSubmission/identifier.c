/*
    
    Bismillahir Rahmanir Rahim. 
    Every praise goes to ALLAH for our wellbeing.
    Code : Kazi Fahim Tahmid
    Judge: Codeforces
    Date : 2023-10-18 05:31
 
    
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int isNum(char x) {
    return (x >= '0' && x <= '9');
}
int isInteger(char *val) {
    int i;
    for (i = 0; i < strlen(val); i++) {
        if (isNum(val[i]) == 0)
            return 0;
    }
    return 1;
}
int isDouble(char *val) {
    int i;
    int f = 0;
    for (i = 0; i < strlen(val); i++) {
        if (isNum(val[i]) == 0) {
            if (val[i] == '.') {
                if (f) {
                    return 0;
                }
                f = 1;
            } else {
                return 0;
            }
        }
    }
    if (f)
        return 1;
    else
        return 0;
}

struct identifier {
    int type;
    char *idname;
    int valtype;
    char *strval;
    int intval;
    double doubleval;
};

struct identifier constructor(int typex, char *varnamex, char *valx) {
    struct identifier data;
    data.type = typex;
    data.idname = (char *)malloc((strlen(varnamex) + 1) * sizeof(char));
    strcpy((data.idname), varnamex);
    if (typex == 1) {  //function
        data.valtype = 1;
        data.intval = atoi(valx);
    }
    else if(typex == 5){ //array
        data.valtype = 5;
        data.intval = atoi(valx+1);
    }
    else if(typex == 6){ //class
        data.valtype = 6;
        data.intval = atoi(valx);
    }
    else {
        if (isInteger(valx)) {
            data.valtype = 2;
            data.intval = atoi(valx);
        } else if (isDouble(valx)) {
            data.valtype = 3;
            data.doubleval = atof(valx);
        } else {
            data.valtype = 4;
            data.strval = (char *)malloc((strlen(valx) + 1) * sizeof(char));
            strcpy(data.strval, valx);
        }
    }
    return data;
}
void print(struct identifier data) {
    if ((data).valtype == 2) {
        printf("name :: %s value :: %d\n", (data).idname,(data).intval);
    } else if ((data).valtype == 3) {
        printf("name :: %s value :: %f\n", (data).idname, (data).doubleval);
    } else if ((data).valtype == 4) {
        printf("name :: %s value :: %s\n", (data).idname, (data).strval);
    } else if (data.valtype == 1) {
        printf("Function name :: %s return type :: %s\n", data.idname,data.strval);
    }
    else if(data.valtype == 5){
        printf("Array name :: %s Dimension :: %d\n", data.idname, data.intval);
    }
    else if(data.valtype == 6){
        printf("Class name :: %s \n",data.idname);
    }
}
void fprint(struct identifier data,FILE* fp) {
    if ((data).valtype == 2) {
        fprintf(fp,"name :: %s value :: %d\n", (data).idname,(data).intval);
    } else if ((data).valtype == 3) {
        fprintf(fp,"name :: %s value :: %f\n", (data).idname, (data).doubleval);
    } else if ((data).valtype == 4) {
        fprintf(fp,"name :: %s value :: %s\n", (data).idname, (data).strval);
    } else if (data.valtype == 1) {
        fprintf(fp,"Function name :: %s return type :: %s\n", data.idname,data.strval);
    }
    else if(data.valtype == 5){
        fprintf(fp,"Array name :: %s Dimension :: %d\n", data.idname, data.intval);
    }
    else if(data.valtype == 6){
        fprintf(fp,"Class name :: %s \n",data.idname);
    }
}

struct ll_identifier {
    struct identifier data;
    struct ll_identifier *next;
};
struct ll_identifier *findClassName(struct ll_identifier **root, int id) {
    struct ll_identifier *now = *root, *ans = NULL;
    while (now != NULL) {
        if (now->data.type == 6 && now->data.intval == id) {
            ans = now;
            break;
        }
        now = now->next;
    }
    return ans;
}
char *gettypename(int id, struct ll_identifier **root) {
    if (id == 0) return "VOID";
    if (id == 1) return "INT";
    if (id == 2) return "DOUBLE";
    if (id == 3)
        return "STRING";
    else {
        struct ll_identifier *res = findClassName(root, id);
        if (res == NULL) {
            printf("Error :: Class not found\n");
            exit(-1);
        }
        return res->data.idname;
    }
}
void push_back_ll(struct ll_identifier **root, struct ll_identifier **last, struct identifier newdata) {
    if(newdata.type == 1){
        newdata.strval = strdup(gettypename(newdata.intval,root));
    }
    struct ll_identifier *new_node = (struct ll_identifier *)malloc(sizeof(struct ll_identifier));
    new_node->data = newdata;
    new_node->next = NULL;
    if (*root == NULL) {
        *root = new_node;
    } else {
        (*last)->next = new_node;
    }
    *(last) = new_node;
    return;
}
struct ll_identifier *isDeclared(struct ll_identifier **root, char *varname) {
    struct ll_identifier *now = *root, *ans = NULL;
    while (now != NULL) {
        if (strcmp(now->data.idname, varname) == 0) {
            ans = now;
            break;
        }
        now = now->next;
    }
    return ans;
}
//id adder
int addNewVal(struct ll_identifier **root, struct ll_identifier **last, char *str, char *val) {
    if (isDeclared(root, str) != NULL)
        return 0;
    int type = 1;
    if (isInteger(val))
        type = 2;
    else if (isDouble(val))
        type = 3;
    else if(val[0]=='`')
        type = 5;
    else if (strlen(val) > 0)
        type = 4;
    struct identifier tmp = constructor(type, str, val);
    push_back_ll(root, last, tmp);
    return 1;
}
struct ll_identifier *getVal(struct ll_identifier **root, char *str) {
    return isDeclared(root, str);
}
void setVal(struct ll_identifier **root, struct ll_identifier **last, char *str, char *val) {
    struct ll_identifier *idx = isDeclared(root, str);
    if (idx == NULL) {
        addNewVal(root, last, str, val);
    }
    else if(idx->data.type == 1 || idx->data.type == 6){
        printf("Error :: You can't set a value to class/function");
        exit(-1);
    }
    else {
        int type = 1;
        if (isInteger(val))
            type = 2;
        else if (isDouble(val))
            type = 3;
        else if (val[0] == '`')
            type = 5;
        else if (strlen(val) > 0)
            type = 4;
        idx->data = constructor(type, str, val);
    }
}
// function adder
int addNewFunc(struct ll_identifier **root, struct ll_identifier **last, char *str, char *val) {
    if (isDeclared(root, str) != NULL)
        return 0;
    int type = 1;
    struct identifier tmp = constructor(type, str, val);
    push_back_ll(root, last, tmp);
    return 1;
}
int addNewClass(struct ll_identifier **root, struct ll_identifier **last, char *str, char *val) {
    if (isDeclared(root, str) != NULL)
        return 0;
    int type = 6;
    struct identifier tmp = constructor(type, str, val);
    push_back_ll(root, last, tmp);
    return 1;
}

void print_all(struct ll_identifier *now) {
    if (now == NULL)
        return;
    print(now->data);
    print_all(now->next);
}
void fprint_all(struct ll_identifier *now,FILE* fp) {
    if (now == NULL)
        return;
    fprint(now->data,fp);
    fprint_all(now->next,fp);
}

//------------------------For expression -------------------------------------//
#ifndef __DT__
#define __DT__
struct __DT__ datatype {
    int type;
    char *strval;
    int intval;
    double doubleval;
};


int max(int a, int b) {
    if (a >= b)
        return a;
    return b;
}
struct datatype make_datatype_int(int val) {
    struct datatype res;
    res.type = 2;
    res.intval = val;
    return res;
}
struct datatype make_datatype_double(double val) {
    struct datatype res;
    res.type = 3;
    res.doubleval = val;
    return res;
}
struct datatype make_datatype_char(char *val) {
    struct datatype res;
    res.type = 4;
    res.strval = calloc(strlen(val) + 1, sizeof(val));
    strcpy(res.strval, val);
    return res;
}
void convert_to_str(struct datatype *a) {
    if (a->type == 2) {
        a->type = 4;
        int n = log10(a->intval) + 1;
        a->strval = calloc(n + 1, sizeof(char));
        snprintf(a->strval, n + 1, "%ld", a->intval);
    } else if (a->type == 3) {
        a->type = 4;
        a->strval = calloc(51, sizeof(char));
        snprintf(a->strval, 50, "%lf", a->doubleval);
    }
}
void convert_to_double(struct datatype *a) {
    if (a->type == 2) {
        a->type = 3;
        a->doubleval = a->intval * 1.0;
    }
}
void makesame(struct datatype *a, struct datatype *b) {
    if (a->type == b->type)
        return;
    if (a->type == 4 || b->type == 4) {
        convert_to_str(a);
        convert_to_str(b);
    } else if (a->type == 3 || b->type == 3) {
        convert_to_double(a);
        convert_to_double(b);
    }
}
struct datatype prepare_for_evaluate(struct datatype *a, struct datatype *b) {
    makesame(a, b);
    struct datatype res;
    if (a->type == 2) {
        res = make_datatype_int(a->intval);
    }
    if (a->type == 3) {
        res = make_datatype_double(a->doubleval);
    }
    if (a->type == 4) {
        res = make_datatype_char(a->strval);
    }
    return res;
}
struct datatype evaluate(struct datatype a, struct datatype b, char *sign) {
    struct datatype res;
    int typex = max(a.type, b.type);
    if (strcmp(sign, "+") == 0) {
        res = prepare_for_evaluate(&a, &b);
        if (typex == 2) {
            res.intval = a.intval + b.intval;
        } else if (typex == 3) {
            res.doubleval = a.doubleval + b.doubleval;
        } else if (typex == 4) {
            realloc(res.strval, (strlen(a.strval) + strlen(b.strval) + 1) * sizeof(char));
            strcat(res.strval, b.strval);
        }
    } else if (strcmp(sign, "*") == 0) {
        if (typex == 2) {
            res = prepare_for_evaluate(&a, &b);
            res.intval = a.intval * b.intval;
        } else if (typex == 3) {
            res = prepare_for_evaluate(&a, &b);
            res.doubleval = a.doubleval * b.doubleval;
        } else if (typex == 4 && (a.type == 2 || b.type == 2)) {
            res.type = 4;
            if (a.type == 2) {
                res.strval = calloc((strlen(b.strval) + 1) * a.intval, sizeof(char));
                for (int i = 0; i < a.intval; i++) {
                    strcat(res.strval, b.strval);
                }
            } else if (b.type == 2) {
                res.strval = calloc((strlen(a.strval) + 1) * b.intval, sizeof(char));
                for (int i = 0; i < b.intval; i++) {
                    strcat(res.strval, a.strval);
                }
            }

        } else {
            printf("Compilation error :: no function found for multiply\n");
            exit(-1);
        }
    } else if (strcmp(sign, "/") == 0) {
        res = prepare_for_evaluate(&a, &b);
        if (a.type == 2) {
            if (a.intval == 0 || b.intval == 0) {
                printf("Runtime Error :: Divide by zero may occur\n");
                exit(-1);
            }
            res.intval = a.intval - b.intval;
        } else if (a.type == 3) {
            if (a.doubleval == 0 || b.doubleval == 0) {
                printf("Runtime Error :: Divide by zero may occur\n");
                exit(-1);
            }
            res.doubleval = a.doubleval - b.doubleval;
        } else {
            printf("Compilation error :: no function found for divide\n");
            exit(-1);
        }
    } else if (strcmp(sign, "-") == 0) {
        res = prepare_for_evaluate(&a, &b);
        if (a.type == 2) {
            res.intval = a.intval - b.intval;
        } else if (a.type == 3) {
            res.doubleval = a.doubleval - b.doubleval;
        } else {
            printf("Compilation error :: no function found for subtract\n");
            exit(-1);
        }
    } else if (strcmp(sign, "<") == 0) {
        prepare_for_evaluate(&a, &b);
        res.type = 2;
        if (a.type == 2 || a.type == 3) {
            res.intval = (a.type == 2 ? a.intval < b.intval : a.doubleval < b.doubleval);
        } else {
            res.intval = (strcmp(a.strval, b.strval) < 0);
        }
    } else if (strcmp(sign, "<=") == 0) {
        prepare_for_evaluate(&a, &b);
        res.type = 2;
        if (a.type == 2 || a.type == 3) {
            res.intval = (a.type == 2 ? a.intval <= b.intval : a.doubleval <= b.doubleval);
        } else {
            res.intval = (strcmp(a.strval, b.strval) <= 0);
        }
    } else if (strcmp(sign, ">") == 0) {
        prepare_for_evaluate(&a, &b);
        res.type = 2;
        if (a.type == 2 || a.type == 3) {
            res.intval = (a.type == 2 ? a.intval > b.intval : a.doubleval > b.doubleval);
        } else {
            res.intval = (strcmp(a.strval, b.strval) > 0);
        }
    } else if (strcmp(sign, ">=") == 0) {
        prepare_for_evaluate(&a, &b);
        res.type = 2;
        if (a.type == 2 || a.type == 3) {
            res.intval = (a.type == 2 ? a.intval >= b.intval : a.doubleval >= b.doubleval);
        } else {
            res.intval = (strcmp(a.strval, b.strval) >= 0);
        }
    } else if (strcmp(sign, "==") == 0) {
        prepare_for_evaluate(&a, &b);
        res.type = 2;
        if (a.type == 2 || a.type == 3) {
            res.intval = (a.type == 2 ? a.intval == b.intval : a.doubleval == b.doubleval);
        } else {
            res.intval = (strcmp(a.strval, b.strval) == 0);
        }
    } else if (strcmp(sign, "!=") == 0) {
        prepare_for_evaluate(&a, &b);
        res.type = 2;
        if (a.type == 2 || a.type == 3) {
            res.intval = (a.type == 2 ? a.intval != b.intval : a.doubleval != b.doubleval);
        } else {
            res.intval = (strcmp(a.strval, b.strval) == 0);
        }
    } else if (strcmp(sign, "%") == 0) {
        if (typex == 2) {
            res = prepare_for_evaluate(&a, &b);
            res.intval = a.intval % b.intval;
        } else {
            printf("Compilation error :: no function found for MODULAS\n");
            exit(-1);
        }
    } else if (strcmp(sign, "&") == 0) {
        if (typex == 2) {
            res = prepare_for_evaluate(&a, &b);
            res.intval = a.intval & b.intval;
        } else {
            printf("Compilation error :: no function found for AND\n");
            exit(-1);
        }
    } else if (strcmp(sign, "^") == 0) {
        if (typex == 2) {
            res = prepare_for_evaluate(&a, &b);
            res.intval = a.intval ^ b.intval;
        } else {
            printf("Compilation error :: no function found for XOR\n");
            exit(-1);
        }
    } else if (strcmp(sign, "|") == 0) {
        if (typex == 2) {
            res = prepare_for_evaluate(&a, &b);
            res.intval = a.intval | b.intval;
        } else {
            printf("Compilation error :: no function found for OR\n");
            exit(-1);
        }
    }
    return res;
}
void print_datatype(struct datatype xx) {
    if (xx.type == 2) {
        printf("%d\n", xx.intval);
    } else if (xx.type == 3) {
        printf("%f\n", xx.doubleval);
    }
    if (xx.type == 4) {
        printf("%s\n", xx.strval);
    }
}
void fprint_datatype(struct datatype xx,FILE *x) {
    if (xx.type == 2) {
        fprintf(x,"%d\n", xx.intval);
    } else if (xx.type == 3) {
        fprintf(x,"%f\n", xx.doubleval);
    }
    if (xx.type == 4) {
        fprintf(x,"%s\n", xx.strval);
    }
}
int boolvalue(struct datatype x){
    if(x.type==2)return x.intval!=0;
    if(x.type==3)return x.doubleval!=0;
    if(x.type==4)return strlen(x.strval)>0;
    return 0;
}
int _intvalue(struct datatype x){
    if(x.type==2)return x.intval;
    if(x.type==3)return (int)x.doubleval;
    return 0;
}
// int main() {
//     struct ll_identifier *root, *last;
//     root = NULL, last = NULL;
//     addNewVal(&root, &last, "abc", "12");
//     addNewVal(&root, &last, "abcx", "12.1");
//     addNewFunc(&root, &last, "des", "int");
//     addNewFunc(&root, &last, "des", "int");
//     print_all(root);
// }
#endif
