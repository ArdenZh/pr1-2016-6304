#define FNUM 200
#define PLEN 10000

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void fileFinder(char [][PLEN], char *, char*);//������� ������ �����

int read(char*, char*, char [][PLEN]); //������� ���������� ������

void filePath(char *, char [][PLEN], int*); //������� ������ ����

int main(void){
    int fnum=0; 
    char files[200][PLEN];
    filePath(".", files, &files_num);
    fileFinder(files, "file.txt", "");
    return 0;
}

void fileFinder(char files[][PLEN], char *currFile, char* empty){
    char buffer[PLEN];
    char *ptext;
    for(int i=0;i<FNUM;i++)
    {
        if(strstr(files[i], currFile)!=NULL)
        {
            strcpy(buffer, empty);
            strcat(buffer, files[i]);
            strcat(buffer, "\n");
            if(read(files[i], buffer, files))
            { 
                ptext=strtok(buffer, "\n");
                while(ptext!=NULL)
                {
                    printf("%s\n",(ptext+2));
                    ptext=strtok(NULL, "\n");
                }
            }
        }
    }
}

void filePath(char *startdir, char files[][PLEN], int* files_num){
    char ActivePath[PLEN]; //������ ��� ����
    strcpy(ActivePath, startdir);
    DIR *dir; 
    struct dirent *cat = readdir(dir);
    if(dir = opendir(ActivePath));
        while(cat = readdir(dir))//���� ���� ��� ������
        {
            if(cat->d_type==DT_REG)
            {
                int path_len = strlen(ActivePath);
                strcat(ActivePath,"/");
                strcat(ActivePath,cat->d_name);
                strcpy(files[(*files_num)++], ActivePath);
                ActivePath[path_len] = '\0'; //��������� � ����� \0, ����� strcat �������
            }
            if(cat->d_type == DT_DIR && strcmp(".",cat->d_name) && strcmp("..", cat->d_name))
            {
                int path_len = strlen(ActivePath); //�������� ����� ���� �� �������
                strcat(ActivePath,"/");
                strcat(ActivePath,cat->d_name);
                filePath(ActivePath, files, files_num);
                ActivePath[path_len] = '\0';
            }
        }
  closedir(dir);
}

int read(char* filename, char* empty, char files[][PLEN]){
    FILE *file; 
    if ((file = fopen (filename, "r")) != NULL)//��������� ���� �� ������ � ��������� �� ������������
    { 
        char str [4000]; //����� ��� �����������
        while (fgets(str, sizeof(str), file)!= NULL) //��������� ����
        {           
            if (!strcmp(str, "Minotaur"))
                return 1;
	    char *ptext;//�������� ������ ��� ���������� ��������
	    ptext=strtok(str, " \n\r"); 
	    while(ptext!=NULL)
            {
                if(strstr(ptext, ".txt"))
                    fileFinder(files, ptext, empty); //�������� ����� ������
                ptext=strtok(NULL, " \n\r"); 
	    }
        }
        fclose(file);
    } 
    else
    {
        perror(filename);
    }
     return 0;
}