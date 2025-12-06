#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50
#define FILE_NAME "group_details.csv"

/* Structure to store student details */
typedef struct {
	char name[NAME_SIZE];
	char surname[NAME_SIZE];
	int id;
	float grade;
} Student;

/* Global dynamic array */
Student *students = NULL;
int count = 0;  // number of students

/* Function prototypes */
void addStudent();
void removeStudent();
void searchStudent();
void displayStudents();
void averageGrade();
void saveToFile();
void loadFromFile();
void freeMemory();

int main() {
	int choice;

	while (1) {
		printf("\n=========== STUDENT MANAGEMENT SYSTEM ===========\n");
		printf("1. Add Student\n");
		printf("2. Remove Student by ID\n");
		printf("3. Search Student by ID\n");
		printf("4. Display All Students\n");
		printf("5. Display Average Grade\n");
		printf("6. Save to File\n");
		printf("7. Load from File\n");
		printf("0. Exit\n");
		printf("Choose an option: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1: addStudent(); break;
			case 2: removeStudent(); break;
			case 3: searchStudent(); break;
			case 4: displayStudents(); break;
			case 5: averageGrade(); break;
			case 6: saveToFile(); break;
			case 7: loadFromFile(); break;
			case 0:
				freeMemory();
				printf("Exiting...\n");
				return 0;
			default: printf("Invalid option! Try again.\n");
		}
	}
}

//ADDING A NEW STUENT
void addStudent() {
	students = realloc(students, (count + 1) * sizeof(Student));

	if (students == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	Student *s = &students[count];

	printf("Enter name: ");
	scanf("%s", s->name);

	printf("Enter surname: ");
	scanf("%s", s->surname);

	printf("Enter ID: ");
	scanf("%d", &s->id);

	printf("Enter grade: ");
	scanf("%f", &s->grade);

	count++;
	printf("Student added successfully!\n");
}

//REMOVE A STUDENT BY ID

void removeStudent() {
	if (count == 0) {
		printf("No students to remove.\n");
		return;
	}

	int id;
	printf("Enter ID to remove: ");
	scanf("%d", &id);

	int index = -1;
	for (int i = 0; i < count; i++) {
		if (students[i].id == id) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		printf("Student not found.\n");
		return;
	}

//Shift elements left
	for (int i = index; i < count - 1; i++) {
		students[i] = students[i + 1];
	}

	count--;
	students = realloc(students, count * sizeof(Student));

	printf("Student removed successfully!\n");
}

//SEARCH STUDENT BY ID
void searchStudent() {
	if (count == 0) {
		printf("No students available.\n");
		return;
	}

	int id;
	printf("Enter ID to search: ");
	scanf("%d", &id);

	for (int i = 0; i < count; i++) {
		if (students[i].id == id) {
			printf("\nStudent Found:\n");
			printf("Name: %s\n", students[i].name);
			printf("Surname: %s\n", students[i].surname);
			printf("ID: %d\n", students[i].id);
			printf("Grade: %.2f\n", students[i].grade);
			return;
		}
	}

	printf("Student not found.\n");
}

// DISPLAY ALL STUDENTS
void displayStudents() {
	if (count == 0) {
		printf("No students to display.\n");
		return;
	}

	printf("\n--------- STUDENT LIST ---------\n");
	for (int i = 0; i < count; i++) {
		printf("%d) %s %s | ID: %d | Grade: %.2f\n",
			i + 1,
			students[i].name,
			students[i].surname,
			students[i].id,
			students[i].grade);
	}
}

//DISPLAY AVERAGE GRADE
void averageGrade() {
	if (count == 0) {
		printf("No students available.\n");
		return;
	}

	float sum = 0;
	for (int i = 0; i < count; i++) {
		sum += students[i].grade;
	}
	printf("Average Grade = %.2f\n", sum / count);
}

//SAVE STUDENT LIST TO CSV
void saveToFile() {
	FILE *fp = fopen(FILE_NAME, "w");
	if (!fp) {
		printf("Error opening file.\n");
		return;
	}

	for (int i = 0; i < count; i++) {
        	fprintf(fp, "%s,%s,%d,%.2f\n",
			students[i].name,
			students[i].surname,
			students[i].id,
			students[i].grade);
	}

	fclose(fp);
	printf("Data saved to %s successfully!\n", FILE_NAME);
}

/*----------------------------------------------------------
                   LOAD STUDENT LIST FROM CSV
-----------------------------------------------------------*/
void loadFromFile() {
	FILE *fp = fopen(FILE_NAME, "r");
	if (!fp) {
		printf("File not found.\n");
		return;
	}

	freeMemory(); // remove old data first
	students = NULL;
	count = 0;

	char line[200];
	while (fgets(line, sizeof(line), fp)) {
		students = realloc(students, (count + 1) * sizeof(Student));
		if (!students) {
			printf("Memory error.\n");
			fclose(fp);
			exit(1);
		}

		Student *s = &students[count];
		sscanf(line, "%[^,],%[^,],%d,%f",
			s->name, s->surname, &s->id, &s->grade);

		count++;
	}

	fclose(fp);
	printf("Data loaded from file successfully!\n");
}

//FREE ALL ALLOCATED MEMORY
void freeMemory() {
	free(students);
	students = NULL;
	count = 0;
}
