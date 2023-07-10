#include <stdio.h>

struct data {
	int key;
	double data1;
	double data2;
	double data3;
};

int linear_search(struct data *, int, int);
int read_data(char*, struct data*);

int main(void) {
	int k;
	struct data d[1000];
	int n;
	int f;

	printf("Input Search Key :");
	scanf("%d", &k);

	n = read_data("data.csv", d);

	f = linear_search(d, k, n);
	if (f == -1) {
		printf("Data Not Found\n");
	}
	else {
		printf("Key = %d Data = %f, %f, %f\n", d[f].key, d[f].data1, d[f].data2, d[f].data3);
	}
	return 0;
}


int read_data(char *file_name, struct data *d) {
	FILE *fp;
	fp = fopen(file_name, "r");
	int n=0;
	
	if (fp == NULL) {
		printf("File not found.");
		return n;
	}

	while (feof(fp) == 0) {
		fscanf(fp, "%d,%lf,%lf,%lf", &d[n].key, &d[n].data1, &d[n].data2, &d[n].data3);
		n++;
	}

	fclose(fp);
	return n;
}


int linear_search(struct data *d, int k, int n) {

	for (int i = 0; i < n; i++)
	{
		if ((d+i)->key == k)    /* If required element is found */
		{
			return i;
		}
	}

	return -1;
}