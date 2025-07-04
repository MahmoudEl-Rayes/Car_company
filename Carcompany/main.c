#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
 struct Calendar {
    int year;
    int month;
    int day;
};
 */
int saveId,CSaveId;
int login=0;
int CarCount,CustomerCount,EmployeeCount;
struct Cars{
    char nameF[20];
    char modelName[20];
    int model;
    char color[20];
    int sold;
    int available;
    int Price;
};
struct Employee{
    char FirstName[20];
    char LastName[20];
    int age;
    char jobTitle[30];
    int salary;
    char pas[20];
};
void ToLower(char*arr)
{
    int i=0;
    while(arr[i]!='\0')
    {
        arr[i]= tolower(arr[i]);
        i++;
    }
}
/*
 struct Installment{
    int index_car;
    //first index time you pay the car second index deadline
    struct Calendar time_you_pay[2];
    int month_Installment;
    struct Calendar deadline;
    // number of month can Installment maximum 3 years
    int arr[36];
};*/
struct Customer{
    char FirstName[20];
    char LastName[20];
    int age;
    int check_installment;
    int NumBuy;
    int buy[10];
   // struct Installment installment[2];
    char pas[12];
};
struct Cars car[100];
struct  Employee employee[100];
struct  Customer customer[100];
void readCustomerData()
{
    FILE *fptr;
    fptr = fopen("CustomerData.txt", "r");
    fscanf(fptr,"%d",&CustomerCount);
    for(int i=0;i<CustomerCount;i++)
    {
        fscanf(fptr,"%s %s %d %s %d ",customer[i].FirstName,customer[i].LastName,&customer[i].age,customer[i].pas,&customer[i].NumBuy);
        for (int j=0;j<customer[i].NumBuy;j++)
        {
            fscanf(fptr,"%d",&customer[i].buy[j]);
        }
    }
    fclose(fptr);
}
void readCarData()
{
    FILE *fptr;
    fptr = fopen("CarsData.txt", "r");
    fscanf(fptr,"%d",&CarCount);
    for(int i=0;i<CarCount;i++)
    {
        fscanf(fptr,"%s %s %s %d %d %d %d",car[i].nameF,car[i].modelName,car[i].color,&car[i].model,&car[i].available,&car[i].sold,&car[i].Price);
        int g=0;
        ToLower(car[i].nameF);
        ToLower(car[i].modelName);
        ToLower(car[i].color);
    }
    fclose(fptr);
}
void SaveCarData()
{
    FILE* file = fopen("CarsData.txt", "w");
    if (file == NULL) {
        printf("File open error.\n");
        return;
    }
    fprintf(file, "%d\n", CarCount);
    for (int i = 0; i <  CarCount; i++)
    {

        fprintf(file, "%s %s %s %d %d %d %d\n",
                car[i].nameF,
                car[i].modelName,
                car[i].color,
                car[i].model,
                car[i].available,
                car[i].sold,
                car[i].Price
              );

    }
    fclose(file);
}
void readEmployeeData()
{
    FILE *fptr;
    fptr = fopen("EmployeeData.txt", "r");
    fscanf(fptr,"%d",&EmployeeCount);
    for(int i=0;i< EmployeeCount;i++)
    {
        fscanf(fptr,"%s %s %s %d %d %s",employee[i].FirstName,employee[i].LastName,employee[i].jobTitle,&employee[i].age,&employee[i].salary,employee[i].pas);
    }
    fclose(fptr);
}
void SaveEmployeeData()
{
        FILE *fptr;
        fptr = fopen("EmployeeData.txt", "w");
                fprintf(fptr,"%d\n",EmployeeCount);
for(int i=0;i<EmployeeCount;i++)
{
fprintf(fptr,"%s %s %s %d %d %s\n",
        employee[i].FirstName,
       employee[i].LastName,
       employee[i].jobTitle,
       employee[i].age,
       employee[i].salary,
       employee[i].pas
       );
}
fclose(fptr);
}
void SaveCustomerData() {
    FILE* file = fopen("CustomerData.txt", "w");
    if (file == NULL) {
        printf("File open error.\n");
        return;
    }
    fprintf(file, "%d\n", CustomerCount);
    for (int i = 0; i <  CustomerCount; i++)
    {
        fprintf(file, "%s %s %d %s %d ",
                customer[i].FirstName,
                customer[i].LastName,
                customer[i].age,
                customer[i].pas,
                customer[i].NumBuy);
        for (int j=0;j<customer[i].NumBuy;j++)
        {
            fprintf(file,"%d ",customer[i].buy[j]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
}
void LeadData()
{
    readCarData();
    readEmployeeData();
    readCustomerData();
}
int CustomerNameSearch(char arr[])
{
    for (int i = 0; i < CustomerCount; i++)
    {
        if (strcmp(customer[i].FirstName, arr) == 0)
        {
            return i;
        }
    }
    return -1;
}
int EmployeeNameSearch(char arr[])
{
    for (int i = 0; i < EmployeeCount; i++)
    {
        if (strcmp(employee[i].FirstName, arr) == 0)
        {
            return i;
        }
    }
    return -1;
}
int choseCus()
{
    while(1)
    {
        system("cls");
        printf("enter user name\n");
        char name[20], pass[20];
        scanf("%s", name);
        printf("enter password\n");
        scanf("%s", pass);
        int can = CustomerNameSearch(name);
        if (can != -1) {
            if (strcmp(customer[can].pas, pass) != 0) {
                system("cls");
                printf("valid username or password\ntry again?\n1-Yes\n2-No\n");
                int try;
                scanf("%d", &try);
                switch (try) {
                    case 1: {
                        continue;
                    }
                    case 2:
                        return -1;
                    default:
                    {
                        printf("en\n");
                        return -1;
                    }
                }
            }
            else
            {
                CSaveId = can;
                return 1;
            }
        }
        else
        {
            system("cls");
            printf("valid username or password\ntry again?\n1-Yes\n2-No\n");
            int try;
            scanf("%d", &try);
            switch (try) {
                case 1:
                {
                    continue;
                }
                case 2:
                {
                    return -1;
                    break;
                }
                default:
                {
                    printf("what are you doing bay");
                    return -1;
                }
            }
        }
    }
}
int choseEmp()
{
while(1)
{
    system("cls");
    printf("enter user name\n");
    char name[20], pass[20];
    scanf("%s", name);
    printf("enter password\n");
    scanf("%s", pass);
    int can = EmployeeNameSearch(name);
    if (can != -1) {
        if (strcmp(employee[can].pas, pass) != 0) {
            system("cls");
            printf("valid username or password\ntry again?\n1-Yes\n2-No\n");
            int try;
            scanf("%d", &try);
            switch (try) {
                case 1: {
                    continue;
                }
                case 2:
                    return -1;
                default:
                    printf("en\n");
                    return -1;
            }
        }
        else
        {
            saveId = can;
            return 1;
        }
    } else
    {
        system("cls");
        printf("valid username or password\ntry again?\n1-Yes\n2-No\n");
        int try;
        scanf("%d", &try);
        switch (try) {
            case 1: {
                continue;
            }
            case 2: {
                return -1;
            }
            default: {
                printf("what are you doing bay");
                return -1;
            }
        }
    }
}
}
int Chose()
{
    int x;
    while (1)
    {
        system("cls");
        printf("\t\t\t\t\t\t\t\t\twelcome to mystery company\n");
        printf("select your account\n");
        printf("1: employee account\n");
        printf("2: customer account\n");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
            {
                int choseE=choseEmp();
                if (choseE == 1)
                {
                    return 1;
                }
                 else if (choseE == -1)
                    continue;
            }
            case 2:
            {
                system("cls");
                printf("1-register\n2-login\n");
                int g;
                scanf("%d",&g);
                switch (g)
                {
                    case 2:
                    {
                        int choseC = choseCus();
                        if (choseC == 1)
                        {
                            return 2;
                        }
                        else if (choseC == -1)
                            continue;
                        break;
                    }
                    case 1:
                    {
                        int count=CustomerCount;
                        while (1)
                        {
                            system("cls");

                            printf("enter First name\n");
                            scanf("%s",customer[count].FirstName);
                           if(CustomerNameSearch(customer[count].FirstName)!=-1)
                           {
                               system("cls");
                               printf("this name is token\n1-enter anthor name\n2-close\n");
                               int s;
                               scanf("%d",&s);
                               if(s==1)
                                   continue;
                               else
                               {
                                   return -1;
                               }
                           }else
                           {
                               break;
                           }
                        }
                        system("cls");
                        printf("enter LastName name\n");
                        scanf("%s",customer[count].LastName);
                        system("cls");
                        printf("enter age\n");
                        scanf("%d",&customer[count].age);
                        printf("enter new password\n");
                        scanf("%s",customer[count].pas);
                        CustomerCount++;
                        system("cls");
                        printf("successfully registered");
                        SaveCustomerData();
                        continue;
                    }
                }
            }
                default:
                    return -1;
        }
    }
}
void ShowCarsData()
{
    system("cls");
    //  int total=0;
    for(int i=0;i<CarCount;i++)
    {
        printf("name: %s\nmodel: %s\ncolor: %s\nyaer: %d\navailable: %d\nsold: %d\nprice: %d$\n",
               car[i].nameF,
               car[i].modelName,
               car[i].color,
               car[i].model,
               car[i].available,
               car[i].sold,
               car[i].Price
        );
        printf("------------------------------------------\n");
    }
}
void ShowCustomerData()
{
    system("cls");
    for(int i=0;i<CustomerCount;i++)
    {
        printf("first name: %s\nlast name: %s\nage: %d\nnumber of car he buyed:%d\n",
               customer[i].FirstName,
               customer[i].LastName,
               customer[i].age,
               customer[i].NumBuy
        );
        printf("------------------------------------------\n");
    }
}
void ShowEmployeeData()
{
    system("cls");
    for(int i=0;i<EmployeeCount;i++)
    {
        printf("first name: %s\nlast name: %s\nJob: %s\nage: %d\nsalary: %d$\n",
               employee[i].FirstName,
               employee[i].LastName,
               employee[i].jobTitle,
               employee[i].age,
               employee[i].salary
        );
        printf("------------------------------------------\n");
    }
}
void AddCar()
{
    int amount=0;
    system("cls");
    struct Cars check;
    printf("enter Name\n");
    scanf("%s",check.nameF);
    printf("enter model Name\n");
    scanf("%s",check.modelName);
    printf("enter color \n");
    scanf("%s",check.color);
    printf("enter year\n");
    scanf("%d",&check.model);
    printf("enter amount \n");
    scanf("%d",&amount);
   int  index=-1;
    for(int i=0;i<CarCount;i++)
    {
      if(strcmp(car[i].nameF,check.nameF)==0)
      {
          index=i;
          break;
      }
    }
    if(index!=-1)
    {
        if((strcmp(car[index].color,check.color)==0)&&(strcmp(car[index].modelName,check.modelName)==0)&&(car[index].model==check.model))
        {
            car[index].available+=amount;
            return;
        }
    }
    system("cls");
    int price;
     printf("this is new car inter Price\n");
    scanf("%d",&price);
   int point=CarCount;
   strcpy(car[point].nameF,check.nameF);
    strcpy(car[point].modelName,check.modelName);
    strcpy(car[point].color,check.color);
   car[point].model=check.model;
    car[point].available=amount;
    car[point].Price=price;
    car[point].sold=0;
    CarCount++;
}
void AddEmployee()
{
    int count=EmployeeCount;
    system("cls");
    while (1)
    {
        system("cls");
        char check[20];
        printf("enter First name\n");
        scanf("%s",check);
        if(EmployeeNameSearch(check)!=-1)
        {
            system("cls");
            printf("this name is token\n1-enter anthor name\n2-return to home page\n");
            int s;
            scanf("%d",&s);
            if(s==1)
                continue;
            else
            {
                return ;
            }
        }else
        {
            strcpy(employee[count].FirstName,check);
            break;
        }
    }
    system("cls");
    printf("enter LastName name\n");
    scanf("%s",employee[count].LastName);
    system("cls");
    printf("enter age\n");
    scanf("%d",&employee[count].age);
    system("cls");
    printf("enter new password\n");
    scanf("%s",employee[count].pas);
    system("cls");
    printf("enter salary\n");
    scanf("%d",&employee[count].salary);
    system("cls");
    printf("enter job Title\n");
    scanf("%s",employee[count].jobTitle);
    EmployeeCount++;
    system("cls");
    printf("successfully added");
    return;
}
void EditEmployee()
{
    system("cls");
    printf("1-Search by Name\n");
    int chose;
    scanf("%d",&chose);
    switch (chose)
    {
        case 1:
        {
            while(1)
            {
                system("cls");
                printf("1-enter Name\n");
                char name[20];
                scanf("%s", name);
                int index = EmployeeNameSearch(name);
                if (index==-1)
                {
                    system("cls");
                    printf("There is no one with that name\n1-try Again\n2-return to main menu\n");
                    int chose2;
                    scanf("%d",&chose2);
                    if(chose2==2)
                    {
                        return;
                    }
                    else if(chose2==1)
                    {
                        continue;
                    }
                }else
                {
                    system("cls");
                    printf("we found the name what you want to edit\n1-first name\n2-last name\n3-job title\n4-age\n5-salary\n");
                    int chose3;
                    scanf("%d",&chose3);
                    switch (chose3)
                    {
                        case 1:
                        {
                            while(1)
                            {
                                system("cls");

                                printf("inter first name\n");
                                char FName[20];
                                scanf("%s", FName);
                                int check= EmployeeNameSearch(FName);
                                if(check==-1)
                                {
                                    strcpy(employee[index].FirstName,FName);
                                    system("cls");
                                    printf("The name has been changed\n");
                                    return;
                                }
                                else
                                {
                                    system("cls");
                                    printf("this name is token\n1-enter anthor name\n2-return to main menu\n");
                                    int chose4;
                                    scanf("%d",&chose4);
                                    if(chose4==2)
                                    {
                                        return;
                                    }
                                    else if(chose4==1)
                                    {
                                        continue;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            system("cls");
                            printf("inter Last name\n");
                            scanf("%s",employee[index].LastName);
                            printf("The last name has been changed\n");
                            return;
                        }
                        case 3:
                        {
                            system("cls");
                            printf("inter job title\n");
                            scanf("%s",employee[index].jobTitle);
                            printf("The job title has been changed\n");

                            return;
                        }
                        case 4:
                        {
                            system("cls");
                            printf("inter age\n");
                            scanf("%d",&employee[index].age);
                            printf("The age has been changed\n");
                            return;
                        }
                        case 5:
                        {
                            system("cls");
                            printf("inter salary\n");
                            scanf("%d",&employee[index].salary);
                            printf("The salary has been changed\n");
                            return;

                        }
                    }
                }
                break;
            }

        }
    }
}
int ShowAvailableCar()
{
    while(1)
    {
        int arr[100] = {-1};
        system("cls");
        int count = 1;
        for (int i = 0; i < CarCount; i++)
        {

            if (car[i].available>0) {
                arr[count] = i;
                printf("(%d)\n", count);
                count++;
                printf("name: %s\nmodel: %s\ncolor: %s\nyaer: %d\nprice: %d$\n",
                       car[i].nameF,
                       car[i].modelName,
                       car[i].color,
                       car[i].model,
                       car[i].Price
                );
                printf("------------------------------------------\n");
            }
        }
        printf("select car number\n");
        int chose;
        scanf("%d",&chose);
        if(chose>count||chose<=0)
        {
            system("cls");
            printf("no car have this number are you joke?\n");
            printf("chose again?\n1-yes\n2-no\n");

            int chose2;
            scanf("%d",&chose2);
            if(chose2==1)
            {
                continue;
            }
            else if(chose2==2)
            {
                return-1;
            }else
            {
                printf("valid number\n");
                return-1;
            }
        }
        else
        {
            return arr[chose];
        }
    }
}
void PrintCar(int i)
{
    printf("name: %s\nmodel: %s\ncolor: %s\nyaer: %d\nprice: %d$\n",
           car[i].nameF,
           car[i].modelName,
           car[i].color,
           car[i].model,
           car[i].Price
    );
    printf("------------------------------------------\n");
}
void SearchCarName(char search[],int*count,int*arr)
{
    int Count=*count;
    for (int i = 0; i < CarCount; i++)
    {
        if (strcmp(search, car[i].nameF) == 0&&car[i].available)
        {
            printf("(%d)\n", Count);
            PrintCar(i);
            *(arr+Count) = i;
            Count++;
        }
    }
    *count=Count;
}
void SearchCarColor(char search[],int*count,int*arr)
{
    int Count=*count;
    for (int i = 0; i <CarCount; i++)
    {
        if (strcmp(search, car[i].color) == 0&&car[i].available)
        {
            printf("(%d)\n", Count);
            PrintCar( i);
            *(arr+Count) = i;
            Count++;
        }
    }
    *count=Count;
}
void SearchCarModeName(char search[],int*count,int*arr)
{
    int Count=*count;
    for (int i = 0; i < CarCount; i++)
    {
        if (strcmp(search, car[i].modelName) == 0&&car[i].available)
        {
            printf("(%d)\n", Count);
            PrintCar( i);
            *(arr+Count) = i;
            Count++;
        }
    }
    *count=Count;
}
void SearchCarModel(int search,int*count,int*arr)
{
    int Count=*count;
    for (int i = 0; i < CarCount; i++)
    {
        if(search==car[i].model&&car[i].available)
        {
            printf("(%d)\n", Count);
            PrintCar( i);
            *(arr+Count) = i;
            Count++;
        }
    }
    *count=Count;
}
void SearchCarRange(int mi,int ma,int*count,int*arr)
{
    int Count=*count;
    for (int i = 0; i < CarCount; i++)
    {
        if(car[i].Price>=mi&&car[i].Price<=ma&&car[i].available)
        {
            printf("(%d)\n", Count);
            PrintCar( i);
            *(arr+Count) = i;
            Count++;
        }
    }
    *count=Count;
}
int SearchCar()
{
    while(1)
    {
        system("cls");
        printf("1-search by name\n");
        printf("2-search by color\n");
        printf("3-search by model name\n");
        printf("4-search by year\n");
        printf("5-select range of price\n");
        int chose;
        scanf("%d", &chose);
        int arr[100] = {-1};
        char search[20];

        switch (chose)
        {

            case 1:
            {
                system("cls");
                printf("1-enter  name\n");
                scanf("%s", search);
                ToLower(search);
                int count = 1;

                SearchCarName(search,&count,arr);
                printf("count=%d\n",count);
                if (count == 1)
                {
                    printf("no car have this name\ntry again?\n1-yes\n2-no\n");
                    int chose2;
                    scanf("%d",&chose2);
                    if(chose2==1)
                    {
                        continue;
                    }else
                    {
                        return -1;
                    }
                }
                printf("select car number\n");
                int chose2;
                scanf("%d",&chose2);
                if(chose2>=count||chose2<=0)
                {
                    system("cls");
                    printf("no car have this number are you joke?\n");
                    printf("chose again?\n1-yes\n2-no\n");

                    int chose3;
                    scanf("%d",&chose3);
                    if(chose3==1)
                    {
                        continue;
                    }
                    else if(chose3==2)
                    {
                        return-1;
                    }else
                    {
                        printf("valid number\n");
                        return-1;
                    }
                }
                else
                {
                    return arr[chose2];
                }
            }
            case 2:
            {
                system("cls");
                printf("1-enter  color\n");
                scanf("%s", search);
                ToLower(search);
                int count = 1;
                SearchCarColor(search,&count,arr);
                if (count == 1)
                {
                    printf("no car have this color\ntry again?\n1-yes\n2-no\n");
                    int chose2;
                    scanf("%d",&chose2);
                    if(chose2==1)
                    {
                        continue;
                    }else
                    {
                        return -1;
                    }
                }
                printf("select car number\n");
                int chose2;
                scanf("%d",&chose2);
                if(chose2>=count||chose2<=0)
                {
                    system("cls");
                    printf("no car have this number are you joke?\n");
                    printf("chose again?\n1-yes\n2-no\n");

                    int chose3;
                    scanf("%d",&chose3);
                    if(chose3==1)
                    {
                        continue;
                    }
                    else if(chose3==2)
                    {
                        return-1;
                    }else
                    {
                        printf("valid number\n");
                        return-1;
                    }
                }
                else
                {
                    return arr[chose2];
                }
            }
            case 3:
            {
                system("cls");
                printf("1-enter  model name\n");
                scanf("%s", search);
                ToLower(search);
                int count = 1;
                SearchCarModeName(search,&count,arr);
                if (count == 1)
                {
                    printf("no car have this model name\ntry again?\n1-yes\n2-no\n");
                    int chose2;
                    scanf("%d",&chose2);
                    if(chose2==1)
                    {
                        continue;
                    }else
                    {
                        return -1;
                    }
                }
                printf("select car number\n");
                int chose2;
                scanf("%d",&chose2);
                if(chose2>=count||chose2<=0)
                {
                    system("cls");
                    printf("no car have this number are you joke?\n");
                    printf("chose again?\n1-yes\n2-no\n");

                    int chose3;
                    scanf("%d",&chose3);
                    if(chose3==1)
                    {
                        continue;
                    }
                    else if(chose3==2)
                    {
                        return-1;
                    }else
                    {
                        printf("valid number\n");
                        return-1;
                    }
                }
                else
                {
                    return arr[chose2];
                }
            }
            case 4:
            {
                int check;
                system("cls");
                printf("1-enter  year\n");
                scanf("%d",&check);
                int count = 1;
                SearchCarModel(check,&count,arr);
                if (count == 1)
                {
                    printf("no car have this year\ntry again?\n1-yes\n2-no\n");
                    int chose2;
                    scanf("%d",&chose2);
                    if(chose2==1)
                    {
                        continue;
                    }else
                    {
                        return -1;
                    }
                }
                printf("select car number\n");
                int chose2;
                scanf("%d",&chose2);
                if(chose2>=count||chose2<=0)
                {
                    system("cls");
                    printf("no car have this number are you joke?\n");
                    printf("chose again?\n1-yes\n2-no\n");

                    int chose3;
                    scanf("%d",&chose3);
                    if(chose3==1)
                    {
                        continue;
                    }
                    else if(chose3==2)
                    {
                        return-1;
                    }else
                    {
                        printf("valid number\n");
                        return-1;
                    }
                }
                else
                {
                    return arr[chose2];
                }
            }
            case 5:
            {
                int mi,ma;
                system("cls");
                printf("1-minimum  Price\n");
                scanf("%d",&mi);
                printf("1-maximum  Price\n");
                scanf("%d",&ma);
                int count = 1;
                SearchCarRange(mi,ma,&count,arr);
                if (count == 1)
                {
                    printf("no car have this year\ntry again?\n1-yes\n2-no\n");
                    int chose2;
                    scanf("%d",&chose2);
                    if(chose2==1)
                    {
                        continue;
                    }else
                    {
                        return -1;
                    }
                }
                printf("select car number\n");
                int chose2;
                scanf("%d",&chose2);
                if(chose2>=count||chose2<=0)
                {
                    system("cls");
                    printf("no car have this number are you joke?\n");
                    printf("chose again?\n1-yes\n2-no\n");

                    int chose3;
                    scanf("%d",&chose3);
                    if(chose3==1)
                    {
                        continue;
                    }
                    else if(chose3==2)
                    {
                        return-1;
                    }else
                    {
                        printf("valid number\n");
                        return-1;
                    }
                }
                else
                {
                    return arr[chose2];
                }
            }
        }
    }
}
int BuyCar()
{
    while (1)
    {
        system("cls");
        printf("1-Show available car\n");
        printf("2-search \n");
        int chose;
        scanf("%d", &chose);
        int check=-1;
        switch (chose)
        {
            case 1:
            {
                check = ShowAvailableCar();
                break;
            }
            case 2:
            {
                 check = SearchCar();
                break;
            }
        }
        if (check == -1)
        {
            system("cls");
            printf("you don't select car\ntry again\n1-yes\n2-no\n");
            int chose2;
            scanf("%d", &chose2);
            if (chose == 1)
            {
                continue;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            system("cls");
            printf("name: %s\nmodel: %s\ncolor: %s\nyear: %d\nprice: %d$\n",
                   car[check].nameF,
                   car[check].modelName,
                   car[check].color,
                   car[check].model,
                   car[check].Price
            );
            printf("you want to by this car?\n1-yes\n2-no and return\n");
            int chose3;
            scanf("%d", &chose3);
            if (chose3 == 1)
            {
                printf("you have account?\n1-yes\n-2create one\n");
                int chose4;
                scanf("%d", &chose4);
                if (chose4 == 1)
                {
                    int choseC = choseCus();
                    if (choseC == 1)
                    {
                        customer[CSaveId].buy[customer[CSaveId].NumBuy] = check;
                        customer[CSaveId].NumBuy++;
                        SaveCustomerData();
                        car[check].available--;
                        car[check].sold++;
                        SaveCarData();
                        return 1;
                    }
                    return -1;
                }
                else
                {
                    int count = CustomerCount;
                    while (1) {
                        system("cls");

                        printf("enter First name\n");
                        scanf("%s", customer[count].FirstName);
                        if (CustomerNameSearch(customer[count].FirstName) != -1)
                        {
                            system("cls");
                            printf("this name is token\n1-enter anthor name\n2-close\n");
                            int s;
                            scanf("%d", &s);
                            if (s == 1)
                                continue;
                            else
                            {
                                return -1;
                            }
                        } else
                        {
                            break;
                        }
                    }

                    system("cls");
                    printf("enter LastName name\n");
                    scanf("%s", customer[count].LastName);
                    system("cls");
                    printf("enter age\n");
                    scanf("%d", &customer[count].age);
                    printf("enter new password\n");
                    scanf("%s", customer[count].pas);
                    customer[count].buy[customer[count].NumBuy] = check;
                    customer[count].NumBuy++;
                    CustomerCount++;
                    system("cls");
                    printf("successfully registered");
                    SaveCustomerData();
                    car[check].available--;
                    car[check].sold++;
                    SaveCarData();
                    return 1;
                }
            }
        }
    }
}
int BuyCCar()
{
    while (1)
    {
        system("cls");
        printf("1-Show available car\n");
        printf("2-search \n");
        int chose;
        scanf("%d", &chose);
        int check=-1;
        switch (chose)
        {
            case 1:
            {
                check = ShowAvailableCar();
                break;
            }
            case 2:
            {
                check = SearchCar();
                break;
            }
        }
        if (check == -1)
        {
            system("cls");
            printf("you don't select car\ntry again\n1-yes\n2-no\n");
            int chose2;
            scanf("%d", &chose2);
            if (chose == 1)
            {
                continue;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            system("cls");
            printf("name: %s\nmodel: %s\ncolor: %s\nyear: %d\nprice: %d$\n",
                   car[check].nameF,
                   car[check].modelName,
                   car[check].color,
                   car[check].model,
                   car[check].Price
            );
            printf("you want to by this car?\n1-yes\n2-no and return\n");
            int chose3;
            scanf("%d", &chose3);
            if (chose3 == 1)
            {
                        customer[CSaveId].buy[customer[CSaveId].NumBuy] = check;
                        customer[CSaveId].NumBuy++;
                        SaveCustomerData();
                        car[check].available--;
                        car[check].sold++;
                        SaveCarData();
                        return 1;

            }else
            {
                return -1;
            }
        }
    }
}
void ChangeEmployeePassword()
{
    while(1)
    {
        system("cls");
        printf("inter current password\n");
        char arr[20];
        scanf("%s",arr);
        if(strcmp(arr,employee[saveId].pas)==0)
        {
            printf("inter new password\n");
            scanf("%s",employee[saveId].pas);
            system("cls");
            printf("password has been changed\n");
            return;
        }else
        {
            system("cls");
            printf("invalid password\ntry again\n1-yes\n2-no");
            int chose;
            scanf("%d",&chose);
            if(chose==1)
            {
                continue;
            }else
                return;
        }
    }
}
void ChangeCustomerPassword()
{
    while(1)
    {
        system("cls");
        printf("inter current password\n");
        char arr[20];
        scanf("%s",arr);
        if(strcmp(arr,customer[CSaveId].pas)==0)
        {
            printf("inter new password\n");
            scanf("%s",customer[CSaveId].pas);
            system("cls");
            printf("password has been changed\n");
            return;
        }else
        {
            system("cls");
            printf("invalid password\ntry again\n1-yes\n2-no");
            int chose;
            scanf("%d",&chose);
            if(chose==1)
            {
                continue;
            }else
                return;
        }
    }
}
void EmployeeFunc()
{
    while (1)
    {
        int choice;
        system("cls");
        printf("welcome %s\n", employee[saveId].FirstName);
        printf("1-show Cars Data\n");
        printf("2-show customer Data\n");
        printf("3-show Employee Data\n");
        printf("4-add Car\n");
        printf("5-add Employee\n");
        printf("6-edit EmployeeData\n");
        printf("7-buy Car\n");
        printf("8-change password\n");
        printf("9-logout\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            {
                ShowCarsData();
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;
            }
            case 2:
            {
                ShowCustomerData();
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;
            }
            case 3:
            {
                ShowEmployeeData();
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;
            }
            case 4:
            {
               AddCar();
               SaveCarData();
                system("cls");
                printf("car has been added\n");
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;
            }
            case 5:
            {
                AddEmployee();
                SaveEmployeeData();
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;
            }
            case 6:
            {
                EditEmployee();
                SaveEmployeeData();
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;

            }
            case 7:
            {

                int check=BuyCar();
                system("cls");
                if(check==1)
                {
                    printf("congratulations for new car\n");
                }
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;
            }
            case 8:
            {
                ChangeEmployeePassword();
                SaveEmployeeData();
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;
            }
            case 9:
            {
                printf("are you sure\n1-Yes\n2-no\n");
                int re;
                scanf("%d", &re);
                if (re == 1)
                {
                    login=1;
                    return;
                } else if (re == 2)
                {
                    continue;
                }
                break;
            }
        }
    }
}
void CustomerFunc()
{
    while (1)
    {
        int choice;
        system("cls");
        printf("welcome,  %s\n", customer[CSaveId].FirstName);
        printf("1-show my cars\n");
        printf("2-Buy car\n");
        printf("3-change password\n");
        printf("4-logout\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                if(customer[CSaveId].NumBuy==0)
                {
                    printf("you don't buy car yet\n");
                }
                else
                {
                    system("cls");
                    for (int i = 0; i < customer[CSaveId].NumBuy; i++)
                    {

                        PrintCar(customer[CSaveId].buy[i]);
                    }
                }
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;
            }
            case 2:
            {
                BuyCCar();
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;
            }
            case 3:
            {
                ChangeCustomerPassword();
                SaveCustomerData();
                printf("return to main menu\n1-Yes\n2-no and close\n");
                int re;
                scanf("%d", &re);
                if (re == 1) {
                    continue;
                } else if (re == 2)
                {
                    return;
                }
                break;
            }
            case 4:
            {
                printf("are you sure\n1-Yes\n2-no\n");
                int re;
                scanf("%d", &re);
                if (re == 1)
                {
                    login=1;
                    return;
                } else if (re == 2)
                {
                    continue;
                }
                break;
            }
        }
    }
}
int main()
{
    while(1)
    {
        login=0;
        LeadData();
        int accountRole = Chose();
        if (accountRole == 1)
        {
            EmployeeFunc();
        }else if(accountRole==2)
        {
            CustomerFunc();
        }
        if(login)
        {
            system("cls");
            printf("login again?\n1-yes\n2-no and close\n");
            int re;
            scanf("%d", &re);
            if(re==1)
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
}