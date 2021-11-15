/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 6. Elabore um programa que armazene o nome completo de uma pessoa com até 30 caracteres e o 
apresente em letras maiúsculas centralizado em uma janela limpa. Na primeira coluna da linha 20 apresente 
quantos caracteres possui este nome e na linha 23 pergunte se o usuário quer informar outro nome. 
Caso deseje repita o processo até que o usuário não deseje mais ler nenhum nome e saia do programa 
IMEDIATAMENTE (sem pressionar qualquer tecla).
*/

//!LIBRARIES _______________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
#include<ctype.h>

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageNameInput();
void messageExit();
void messageName(char *text, int size);
void messageAnotherName();

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError, int option);
void errorExit();

//! VALIDATION INPUT __________________________________________________________________________________________
bool validationString(char *string);

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();
void functionInputString(char *text, int size);
void functionFormateString(char *text);
int functionToInput();



int main()
{
    int size, option, nameLen;
    char fullName[30];
    bool validation = false, exitValidation = false;
    

    size = sizeof(fullName)/sizeof(fullName[0]);

    messageTitle();

    do
    {
        functionInputString(fullName, size);
        nameLen = strlen(fullName);
        functionFormateString(fullName);
        messageName(fullName, nameLen);
        option = functionToInput();
        system("cls");
       
    } while (option != 2);

    system("cls");
    messageExit();
    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA ENTRAR UM NOME.\n\n\n");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput()
{
    printf("DIGITE O UM TEXTO: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    system("cls");
    printf("O SISTEMA IR\265 FINALIZAR\n");
}

//  MESSAGE TO PRINT THE NAMES
void messageName(char *text, int size)
{      
    printf("\t\t\t\t\t%s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", text);
    printf("ESTE NOME POSSUI: %d caracteres\n\n\n", size);
}

//  MESSAGE TO AKS USER IF WANTS TO INPUT ANOTHER NAME
void messageAnotherName()
{      
    printf("PRESSIONE UMA TECLA SE DESEJA ENTRAR COM OUTRO NOME?\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("DIGITE UMA OP\200\307O: ");
}

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError, int option)
{
    switch (option)
    {
    case 1:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
        break;
    
    case 2:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM NOME V\265LIDO\n\n\n");
        break;

    default:
        break;
    }
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! VALIDATION INPUT __________________________________________________________________________________________

//  FUNCTION TO VALIDATE A STRING
bool validationString(char *string)
{
    int index = 0;

    if (strlen(string) == 1)
    {
        if (string[index] == '\n' || string[index] == ' ' || string[index] == '\0' || string[index] == '\r' || 
        string[index] == '\r\n' || !isalpha(string[index] || !isdigit(string[index])))
        {
            return false;
        }
    }
    else
    {
        while (index < strlen(string))
        {
            if (string[index] != "\n" && string[index] != " " && string[index] != "\0" && string[index] != "\r" && 
            string[index] != "\r\n" && !isspace(string[index]) && (isalpha(string[index]) || isdigit(string[index])))
            {
                return true;
            }
            index++;
        }

        return false;
    }

    return false;
}

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION INPUT STRING
void functionInputString(char *text, int size)
{
    int quantityOfError = 0, count = 0;
    bool validation = false;

    while (validation == false)
    {
        messageNameInput();
        fflush(stdin);
        fgets(text, size, stdin);
        validation = validationString(text);

        if (strlen(text) == (size - 1))
        {
            char charactere;
            while ((charactere = getchar()) != '\n' && charactere != EOF);
        }

        if (validation == false)
        {
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 2);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
        }
    }

    system("cls");
    count = 0;
    validation = false;
}

//  FUNCTION TO UPPER A STRING
void functionFormateString(char *text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        text[i] = toupper(text[i]);
    }
}

//  FUNCTION TO CHOOSE 
int functionToInput()
{
    int option = 0, quantityOfError = 0;
    bool validation = false;
    
    do
    {
        messageAnotherName();
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            validation = true;
            quantityOfError = 0;
            return option;
            break;

        case 2:
            validation = true;
            quantityOfError = 0;
            return option;
            break;
        
        default:
            validation = false;
            quantityOfError++;
            
            errorMessageInput(quantityOfError, 1);

            if(quantityOfError == 3)
            {
                errorExit();
            }
            break;
        }

    } while (validation == false);
}
