#include<stdio.h>
/*
Name: BUKENYA JOHN MATTHIAS
Registration Number: 23/U/BIO/025/GV
*/
int main(){
    int courseCodes1[8] = {1101,1102,1103,1104,1105,1106,1107,1108};
	int courseCodes2[8]={1201,1202,1203,1204,1205,1206,1207,1208};
    int marks1[8], marks2[8];
    
    // Entering Semester I marks
    printf("ENTER MARKS FOR SEMESTER I\n");
    for(int i=0; i<8; i++){
        printf("TEMB %d: ", courseCodes1[i]);
        scanf("%d", &marks1[i]);
        if(marks1[i] < 0 || marks1[i] > 100){
        printf("Invalid score entered! Please enter between 0 and 100.\n");
        i--;
    }  
    }

    // Entering Semester II marks
    printf("\nENTER MARKS FOR SEMESTER II\n");
    for(int i=0; i<8; i++){
        printf("TEMB %d: ", courseCodes2[i]);
        scanf("%d", &marks2[i]);
        if(marks2[i] < 0 || marks2[i] > 100){
        printf("Invalid score entered! Please enter between 0 and 100.\n");
        i--;
    }
}
    //storing credit units for semester 1
    int credits1[8] = {4,3,3,3,3,3,2,3};
    //storing credit units for semester 2
    int credits2[8] = {4,3,3,3,3,3,3,3};

    // Calculating Gpa
    float total_GP1 = 0, total_CU1 = 0;
    float total_GP2 = 0, total_CU2 = 0;
    //weighted is the weighted contribution which product of grade point and credit unit
    int weighted;
    int grade_point;
    char grade;
    //Semester 1 GPA
    printf("\n SEMESTER I REPORT \n");
    printf("Code\t\tMarks\tGrade\tGP\tCU\tWeighted_Contribution\n");
    for(int i=0; i<8; i++){
        int marks = marks1[i];
        if(marks >= 80){ 
		grade='A'; 
		grade_point=5; }
        else if(marks >= 70){ 
		grade='B'; 
		grade_point=4; }
        else if(marks >= 60){ 
		grade='C'; 
		grade_point=3; }
        else if(marks >= 50){
		 grade='D'; 
		 grade_point=2; }
        else { 
		grade='F'; 
		grade_point=0; }
        
        weighted = grade_point * credits1[i];
        total_GP1 = total_GP1+ weighted;
        total_CU1 =total_CU1+ credits1[i];

        printf("TEMB %d\t%d\t%c\t%d\t%d\t%d\n", courseCodes1[i], marks, grade, grade_point, credits1[i], weighted);
    }
    float gpa1 = total_GP1 / total_CU1;

    //Semester 2 GPA
    printf("\n SEMESTER II REPORT \n");
    printf("Code\t\tMarks\tGrade\tGP\tCU\tWeighted\n");
    for(int i=0; i<8; i++){
        int marks = marks2[i];
        if(marks >= 80){
		 grade='A'; 
		 grade_point=5; }
        else if(marks >= 70){
		 grade='B'; 
		 grade_point=4; }
        else if(marks >= 60){
		 grade='C'; 
		 grade_point=3; }
        else if(marks >= 50){ 
		grade='D'; 
		grade_point=2; }
        else { 
		grade='F';
		 grade_point=0; }

        weighted = grade_point * credits2[i];
        total_GP2 += weighted;
        total_CU2 += credits2[i];

        printf("TEMB %d\t%d\t%c\t%d\t%d\t%d\n", courseCodes2[i], marks, grade, grade_point, credits2[i], weighted);
    }
    float gpa2 = total_GP2 / total_CU2;

    // Calculating CGPA
    float cgpa = (gpa1 + gpa2) / 2;
    
    char classification[30];
   

    // Final report
    printf("\nSemester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);
    if(cgpa >= 4.4 && cgpa <= 5.0){
    printf("Classification: First Class\n");}
else if(cgpa >= 3.6 && cgpa <= 4.39){
    printf("Classification: Second Class Upper\n");}
else if(cgpa >= 2.8 && cgpa <= 3.59){
    printf("Classification: Second Class Lower\n");}
else if(cgpa >= 2.0 && cgpa <= 2.79){
    printf("Classification: Pass\n");}
else{
    printf("Classification: Fail\n");}

    return 0;
}

