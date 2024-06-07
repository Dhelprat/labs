#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	char op;
	char letter;
	int znach;
	struct node* left_child;
	struct node* right_child;
};

struct vector {
	int size;
	int real_size;
	int* mass;
};

struct vector* vector_create(int n) {
	struct vector* mass = malloc(sizeof(struct vector));
	int j = ((n / 100 + 1) * 100);
	int* st = malloc( j* sizeof(int));
	mass->mass = st;
	mass->size = n - 1;
	mass->real_size = j;
	return mass;
}

void push_back(struct vector* v, int c) {
	if (v->real_size <= (v->size) + 1)
	{
		v->mass = realloc(v->mass, (v->real_size + 100) * sizeof(int));
		v->real_size += 100;
	}
	v->mass[v->size + 1] = c;
	v->size++;
}

int check_num(char c) {
	return (c <= '9' && c >= '0');
}

int check_letter(char c) {
	return (c <= 'z' && c >= 'a');
}

const int INF = INT_MAX;
struct node* build_tree(int l, int r, struct vector* st, struct vector* pr) {
	int mpr = INF, mind = INF;
	for (int i = l; i <= r; i++) {
		if (pr->mass[i] < mpr && st->mass[i]!='(' && st->mass[i] != ')') {
			mpr = pr->mass[i];
			mind = i;
		}
	}
	struct node* el = malloc(sizeof(struct node));
	if (st->mass[mind] == '-' && st->mass[mind - 1]=='(') {
		if (check_letter(st->mass[mind + 1]) == 1) {
			el->op = '!';
			el->znach = -1;
			el->letter = st->mass[mind + 1];
		}
		else {
			int ans = 0, pw = 1;
			for (int i = r; i >= mind+1; i--)
			{
				if (st->mass[i] == ')')
					continue;
				ans += (st->mass[i] - '0') * pw;
				pw *= 10;
			}
			ans *= -1;
			el->op = '!';
			el->znach = ans;
			el->letter = '!';
		}

		el->left_child = NULL;
		el->right_child = NULL;
	}
	else if (check_num(st->mass[mind]) == 1) {
		int ans = 0, pw = 1;
		for (int i = r; i >= mind; i--)
		{
			if (st->mass[i] == ')')
				continue;
			ans += (st->mass[i] - '0') * pw;
			pw *= 10;
		}
		el->op = '!';
		el->znach = ans;
		el->letter = '!';
		el->left_child = NULL;
		el->right_child = NULL;
	}
	else if (check_letter(st->mass[mind]) == 1) {
		el->op = '!';
		el->letter = st->mass[mind];
		el->znach = INF;
		el->left_child = NULL;
		el->right_child = NULL;
	}
	else if (st->mass[mind] == '-' || st->mass[mind] == '+' || st->mass[mind] == '*' || st->mass[mind] == '/') {
		el->op = st->mass[mind];
		el->znach = INF;
		el->left_child = build_tree(l, mind - 1, st, pr);
		el->right_child = build_tree(mind+1,r, st, pr);
	}
	return el;
}

void printer(struct node* cur, int level) {
	if (cur == NULL)
		return;
	for (int i = 0; i < level; ++i)
		printf("	");

	if(cur->op!='!')
		printf("%c\n", cur->op);
	else if (cur->letter != '!') {
		if(cur->znach==-1)
			printf("-%c\n", cur->letter);
		else
			printf("%c\n", cur->letter);
	}
	else
		printf("%d\n", cur->znach);

	printer(cur->left_child, level + 1);
	printer(cur->right_child, level + 1);
}

int perenos(struct node* cur, struct node* prev) {
	if (cur == NULL)
		return -1;
	if (cur->znach != INF && (prev->op == '*' || prev->op == '/')) {
		cur->znach *= -1;
		return 1;
	}
	if (cur->letter != '!' && (prev->op == '*' || prev->op == '/')) {
		if (cur->znach == -1)
			cur->znach = 1;
		else
			cur->znach = -1;
		return 1;
	}
	int ok = perenos(cur->left_child, cur);
	if(ok==-1)
		return perenos(cur->right_child, cur);
	return ok;
}

void dfs(struct node* prev, struct node* cur, int napr) {
	if (cur == NULL)
		return;
	if (cur->znach == -1) {
		struct node* next;
		if (napr == 0)
			next = prev->right_child;
		else
			next = prev->left_child;
		if (perenos(next,prev) == 1)
			cur->znach *= -1;
	}
	if (cur->letter=='!' && prev != NULL && cur->znach == 1 && prev->op == '*') {
		struct node* delited1;
		struct node* delited2;
		delited1 = prev->left_child;
		delited2 = prev->right_child;
		if (napr == 0) {
			prev->op = prev->right_child->op;
			prev->znach = prev->right_child->znach;
			prev->letter = prev->right_child->letter;
			prev->left_child = delited2->left_child;
			prev->right_child = delited2->right_child;
		}
		else if (napr == 1) {
			prev->op = prev->left_child->op;
			prev->znach = prev->left_child->znach;
			prev->letter = prev->left_child->letter;
			prev->left_child = delited1->left_child;
			prev->right_child = delited1->right_child;
		}
		free(delited1);
		free(delited2);
	} else {
		dfs(cur, cur->left_child, 0);
		dfs(cur, cur->right_child, 1);
	}
}

void print_st(struct node* cur) {
	if (cur == NULL)
		return;
	if (cur->op == '!' && cur->letter != '!') {
		if(cur->znach==-1)
			printf("-%c", cur->letter);
		else
			printf("%c", cur->letter);
	}
	else if (cur->znach != INF) {
		if (cur->znach < 0)
			printf("(%d)", cur->znach);
		else
			printf("%d", cur->znach);
	}
	else if (cur->op != '!') {
		if (cur->op == '+' || cur->op == '-') {
			print_st(cur->left_child);
			printf("%c", cur->op);
			print_st(cur->right_child);
		}
		else {
			if (cur->left_child->op == '+' || cur->left_child->op == '-') {
				printf("("); print_st(cur->left_child); printf(")");
			} else
				print_st(cur->left_child);
			printf("%c", cur->op);
			if (cur->right_child->op == '+' || cur->right_child->op == '-'){
				printf("("); print_st(cur->right_child); printf(")");
			} else
				print_st(cur->right_child);
		}
	}
}

int main() {
	struct vector* str;
	struct vector* priority;

	str = vector_create(0);
	priority = vector_create(0);

	push_back(str, '!');
	push_back(priority, 0);

	char c = '!';
	while (c != '\n') {
		scanf("%c", &c);
		if (c == '\n')
			break;
		push_back(str, c);
		if (c == '(')
			push_back(priority, priority->mass[priority->size] + 1);
		else if(c == '+' || c=='*' || c=='/' || c == ')' || c=='-')
			push_back(priority, priority->mass[priority->size] - 1);
		else if(check_num(c)==1 && check_num(str->mass[str->size-1])==1)
			push_back(priority, priority->mass[priority->size]);
		else if (check_num(c) == 1 || check_letter(c) == 1)
		{
			push_back(priority, priority->mass[priority->size] + 1);
			if (str->mass[str->size - 1] == '-' && str->mass[str->size - 2] == '(')
			{
				priority->mass[priority->size - 1]+=2;
				priority->mass[priority->size]++;
			}
		}
	}
	struct node* tree = build_tree(1,str->size,str, priority);

	dfs(NULL,tree,-1);

	printer(tree, 0);
	print_st(tree);
}