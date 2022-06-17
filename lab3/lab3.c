#include <stdlib.h>

#include <stdio.h>
#include <string.h>




typedef struct person {
	char name[20];
	char surname[20];
	char sex[8];
	char position[20];
	unsigned int salary;
} person;

void set_data(char string[], int* k, char fld[])
{

	int i = *k;
	while ((string[i] == ',') || (string[i] == '\"'))
	{
		i++;
	}
	int j = 0;
	while (string[i] != '\"')
	{
		fld[j] = string[i];
		i++;
		j++;
	}
	fld[j] = '\0';
	*k = i;
}




int main(int argc, char* argv[]) {
	FILE* fp;
	char string[255];

	int n = 0, i;
	person* prsn = NULL;
	person tmp;

	if (argc != 3) {
		printf("CSV scanner. Counts median salary on choosen position.\n Usage:\n csv.exe <filename> <position>\n");
		return 2;
	}

	if (NULL == (fp = fopen(argv[1], "r"))) {
		fprintf(stderr, "cannot open file '%string'", argv[1]);
		return 1;
	}
	if (!(fopen_s(&fp, argv[1], "r"))) {
		fgets(string, 255, fp);
		while (!feof(fp)) {
			fgets(string, 255, fp);
			prsn = (person*)realloc(prsn, (n + 1) * sizeof(person));
			i = 0;
			set_data(string, &i, prsn[n].name);
			set_data(string, &i, prsn[n].surname);
			set_data(string, &i, prsn[n].sex);
			set_data(string, &i, prsn[n].position);
			sscanf_s(&string[i + 3], "%d", &prsn[n].salary);
			n++;
		}
		fclose(fp);
	}



	unsigned int* salary = NULL;

	salary = (unsigned int*)realloc(salary, sizeof(unsigned int));
	int k = 0;
	if (salary != NULL) {
		for (int f = 0; f < n - 1; f++) {
			if (0 == strcmp(prsn[f].position, argv[2])) {
				salary[k] = prsn[f].salary;
				salary = (unsigned int*)realloc(salary, (k + 2) * sizeof(unsigned int));
				k++;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = k;j > i; j-- ) {
			if (salary[j - 1] > salary[j]) {
				unsigned int tmp = salary[j - 1];
				salary[j - 1] = salary[j];
				salary[j] = tmp;
		}
		}
	}
	if (k % 2 == 1) {
		printf("The median salary is: %d ", salary[k / 2]);
	}

	else {
		int med = (salary[k / 2] + salary[(k / 2) - 1]) / 2;
		printf("The median salary is: %d", med);
	}



}