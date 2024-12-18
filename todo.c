#include<stdio.h>
#include<string.h>

// Task strukturasini yaratamiz
typedef struct {
    char title[128];  // Vazifaning nomi
    char description[512];
    int status;       // 1 - "Bajarilgan", 0 - "Bajarilmagan"
} Task;

Task tasks[100];  // Vazifalar ro'yxati
int count = 0;    // Hozirgi vazifalar soni

int exitt = 1;

// add_task - Yangi vazifa qo'shish
void add_task() {
    char arr_title[128], arr_description[512];
    printf("Enter task title :");
    
    //add_task titlega ga to`g`ridan to`gri bera olmaymiz shuning uchun, arr_title ga berib olamiz 
    fgets(arr_title, sizeof(arr_title), stdin);

    for (int i = 0; arr_title[i + 1] != '\0'; i++)
    {
        tasks[count].title[i] = arr_title[i];
    }

    printf("Enter task description :");
    // add_task description ga to`g`ridan to`gri bera olmaymiz shuning uchun, arr_description  ga berib olamiz
    fgets(arr_description, sizeof(arr_description), stdin);
    for (int i = 0; arr_description[i + 1] != '\0'; i++)
    {
        tasks[count].description[i] = arr_description[i];
    }
    //yangi buyruq kiritilganda status 0 bolishi
    tasks[count].status = 0;

    printf("Task added successfully!\n");
    count++;
};

// list_all_tasks - Barcha vazifalarni ro'yxatini ko'rsatish
void list_all_tasks(){
    if(count == 0){
        printf("Buyruqlar mavjud emas. Iltimos avval buyruq kiriting\n");
    }else
    {
        printf(" ID|        Title|               Description| Status\n----------------------------------------------------------\n");
        for (int i = 0; i < count; i++)
        {
            if (tasks[i].status != -1) 
            {
                printf("%3d", i + 1);
                printf("| %12s", tasks[i].title);
                printf("| %25s", tasks[i].description);
                if (tasks[i].status == 0)
                {
                    printf("| bajarilmagan\n");
                }
                else
                    printf("| bajarilgan\n");
            }
            
        }
        
    }
    
};

// get_task_by_id - Vazifani ID bo'yicha ko'rsatish
void get_task_by_id(){
    //ID raqamini kiritish uchun o`zgaruvchi
    int n, deleted_index;

    printf("Izlayotgan vazifani ni ID raqamini kiriting: ");
    scanf("%d", &n);

    deleted_index = tasks[n - 1].status;
    if ((n - 1 <= count) && (count != 0) && deleted_index != -1)
    {
        printf("%3d", n);
        printf("| %12s", tasks[n - 1].title);
        printf("| %25s", tasks[n - 1].description);
        if (tasks[n - 1].status == 0)
        {
            printf("| bajarilmagan\n");
        }
        else
            printf("| bajarilgan\n");
    }else
    {
        printf("izlanayotgan vazifa mawjud emas ");
    }
    
    
};

// delete_task_by_id - Vazifani ID bo'yicha o'chirish
void delete_task_by_id(){
    // ID raqamini kiritish uchun o`zgaruvchi
    int n;


    printf("O`chirmoqchi bo`lgan vazifani ni ID raqamini kiriting: ");
    scanf("%d", &n);
    if ((n - 1 <= count) && (count != 0))
    {
        if (tasks[n-1].status != -1)
        {
            tasks[n - 1].status = -1;
            printf("Task deleted successfully!\n");
        } else
        {
            printf("Bu ID allaqachon o`chirilgan");
        }
        
        
    }else
    {
        printf("Bunday ID da vazifa kiritilmagan!\nIltimos boshqa ID kiriting: ");
    }
    
    };

// mark_task_completed - Vazifani "Completed" deb belgilash
void mark_task_completed(){
    // ID raqamini kiritish uchun o`zgaruvchi
    int n;

    printf("Bajarilgan vazifani ni ID raqamini kiriting: ");
    scanf("%d", &n);

    if (n - 1 <= count && count != 0)
    {
        while (tasks[n - 1].status == 1)
        {
            printf("Bu vazifa bajarilgan!\nIltimos, boshqa vazifa ID sini kiriting: ");
            scanf("%d", &n);
        }
        tasks[n - 1].status = 1;
        printf("Vazifa bajarildi deb bilgilandi :)\n");
    }else
    {
        printf("Bunday ID da vazifa mavjud emas, iltimos boshqa ID ni kiriting!\n");
    }
    
    
};

// mark_task_incomplete - Vazifani "Incomplete" deb belgilash
void mark_task_incomplete(){
    // ID raqamini kiritish uchun o`zgaruvchi
    int n;

    printf("Bajarilmagan vazifani ni ID raqamini kiriting: ");
    scanf("%d", &n);
    if (n - 1 <= count && count != 0)
    {
        while (tasks[n - 1].status == 0)
        {
            printf("Bu vazifa shundog` ham bajarilmagan!\nIltimos, boshqa vazifa ID sini kiriting: ");
            scanf("%d", &n);
        }

        tasks[n - 1].status = 0;
        printf("Vazifa bajarilmadi deb bilgilandi :(\n");
    }else
        {
            printf("Bunday ID da vazifa mavjud emas, iltimos boshqa ID ni kiriting!\n");
        }
    };

// show_menu - Foydalanuvchiga menyuni ko'rsatish
void show_menu(void){
printf("To-Do List Menu:\n1. Add Task\n2. List Tasks\n3. Get Task by ID\n4. Delete Task\n5. Mark Task as Completed\n6. Mark Task as Incompleted\n7-menu ni qayta ko`rish\n8. Exit\n");
}
int main(){

    printf("To-Do List Menu:\n1. Add Task\n2. List Tasks\n3. Get Task by ID\n4. Delete Task\n5. Mark Task as Completed\n6. Mark Task as Incompleted\n7-menu ni qayta ko`rish\n8. Exit\n");
    
    while (exitt != 8)
    {  
        printf("\nQaysi menu ga murojaat qilishni hohlaysiz: ");
        scanf("%d", &exitt);
        // Kirish buferini tozalash
        while (getchar() != '\n')
            ;
        switch (exitt)
        {
        case 1:
            add_task();
            break;
        case 2:
            list_all_tasks();
            break;
         case 3:
             get_task_by_id();
             break;
        case 4:
            delete_task_by_id();
            break;
        case 5:
            mark_task_completed();
            break;
        case 6:
            mark_task_incomplete();
            break;
         case 7:
             show_menu();
             break;
         case 8:
             break;
        
         default:
             printf("Siz noto`gri menu tanladingiz!\n Iltimos mavjud bo`lgan menu ni tanlang: ");
             break;

        }
    }

    printf("Bizni xizmatimizdan foydalanganingiz uchun juda mamnunmiz :)!!\nIshlaringizga Alloh baraka bersin");
    
}