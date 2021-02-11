/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
	char categories[NUM_QUESTIONS][MAX_LEN] = {
		"programming",
		"programming",
		"programming",
		"programming",
		"algorithms",
		"algorithms",
		"algorithms",
		"algorithms",
		"databases",
		"databases",
		"databases",
		"databases"
	};
    	char questions[NUM_QUESTIONS][MAX_LEN] = {
		"It is the most widely used systems programming language",
		"It is the most widely used programming language for AI research",
		"An example of this type of data would be a word in plain English",
		"This type of fault is incredibly frustrating and difficult to debug",
		"This sequence is when you add the previous 2 terms together to get the next term",
		"The ___ algorithm imitates the evolutionary process",
		"An algorithm that calls itself is known as:",
		"A technique where you sequentially try every possible combination",
		"Google's primary cloud storage suite",
		"The industry standard database programming language ",
		"All databses are comprised of these constructs to store data entries",
		"The ____ key is used to uniquely identify entries in a database"
	};
	char answers[NUM_QUESTIONS][MAX_LEN] = {
		"C",
		"Python",
		"String",
		"Segfault",
		"Fibbonacci",
		"Genetic",
		"Recursive",
		"Brute-force",
		"Drive",
		"SQL",
		"Table",
		"Primary"
	};
    	int values[NUM_QUESTIONS] = {
		20,
		50,
		100,
		200,
		20,
		50,
		100,
		200,
		20,
		50,
		100,
		200
	};
	for(int i = 0; i<NUM_QUESTIONS; i++){
		question q = {
			categories[i],
			questions[i],
			answers[i],
			values[i],
			false
		}
		questions[i]=q;
	}
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
	for(int i = 0; i<NUM_QUESTIONS; i++){
		if (!questions[i].answered){
			printf("%s   %d", &questions[i].question, &questions[i].value);
		}
	}
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	for(int i = 0; i<NUM_QUESTIONS; i++){
		if (questions[i].category==category && questions[i].value==value){
			printf("%s", &questions[i].question);
		}
	}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
	for(int i = 0; i<NUM_QUESTIONS; i++){
		if (questions[i].category==category && questions[i].value==value 
			&& strcmp(questions[i].answer, answer)==0){
			return true;
		}
	}
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
	for(int i = 0; i<NUM_QUESTIONS; i++){
		if (questions[i].category==category && questions[i].value==value && questions[i].answered){
			return true;
		}
	}
    return false;
}
