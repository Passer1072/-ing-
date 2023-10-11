#include <stdio.h>
// 全局变量
int choice;
int const MaxStu = 5;
int passer[5][2]; // 特殊：数组的维度必须是常量表达式


void xuanxiang(){
    // 打印选项
    printf("   菜  单\n");
    printf("1.学生成绩录入\n");
    printf("2.学生成绩修改\n");
    printf("3.学生成绩删除\n");
    printf("4.学生成绩查询\n");
    printf("5.学生成绩保存\n");
    printf("6.学生成绩排序(选择)\n");
    printf("7.学生成绩排序(冒泡)\n");
    printf("8.读取存储的成绩\n");
    printf("0.退       出\n");
    printf("请输入序号：");
    // scanf 是 C 语言中用于从用户或文件读取输入的函数，它的意思是扫描格式化字符串。
    scanf("%d", &choice);
}           // 定义函数xuanxiang打印全部选项，并保存用户输入的项目编号
void luRu(){
    // 录入成绩
    for (
            int i = 0; i < MaxStu ; ++i) {
        //自动写入行号
        passer[i][0] = i + 1;
        //手动输入第二列成绩
        printf("请输入%d学生成绩：", i + 1);
        scanf("%d", &passer[i][1]);
    }

    // 打印二维数组
    for (int i = 0; i < MaxStu ; ++i) {
        // 打印第0列学号
        printf("%-5d", passer[i][0]);
        // 打印第1列成绩
        printf("%d分\n", passer[i][1]);
    }
}                // 定义函数luRu进行成绩录入。
void xiuGai(){
    int StudentID;
    printf("输入学号：");
    scanf("%d", &StudentID);

    int found = 0; // 用于标记是否找到学生

    for (int i = 0; i < 5; ++i) {
        if (passer[i][0] == StudentID) {
            printf("请输入新的成绩：");
            scanf("%d", &passer[i][1]);
            found = 1; // 标记为找到学生
            break; // 找到学生后退出循环
        }
    }

    if (!found) {
        printf("未找到该学生\n");
    }
}              // 定义函数xiuGai进行成绩修改
void DeleteStuGrades(){
    int StuNumber;
    int Found = 0;
    printf("请输入要删除的学号:");
    // 读取学号
    scanf("%d",&StuNumber);
    // 查找要删除的学生学号索引
    // 从0行开始遍历二位函数
    for (int i = 0; i < MaxStu; ++i) {
        // 判断是否找到
        if(passer[i][0] == StuNumber){
            // 返回值，已找到学生
            Found = 1;
            printf("已找到学生,开始删除\n");
            // 从要删除的位置开始，将后续学生数据依次上移
            for (int j = i; j < MaxStu - 1; ++j) {
                passer[j][0] = passer[j + 1][0];
                passer[j][1] = passer[j + 1][1];

            }
            // 清除最后一行的数据
            passer[MaxStu - 1][0] = 0;
            passer[MaxStu - 1][1] = 0;
            printf("删除完成\n");

            // （优化）删除完成后直接break打断退出循环
            break;
        }
    }
    // 真假函数判断
    if(!Found){
        printf("未找到该学生\n");
    }
}     // 法一（BUG-已解决）：定音函数DeleteStuGrades进行成绩删除
void chaXun(){
    int X;
    int exitFlag = 0;
    // while (!exitFlag)为真（1）时结束循环，为假（0）时继续循环。
    while (!exitFlag) {
        printf("输入要查询的编号（0退出）：");
        // 从键盘输入存储在X中。
        scanf("%d", &X );
        // ==用于判断左右两边，判断选项X是否为0.
        if (X == 0){
            // 退出循环的编号
            exitFlag = 1;
        } else {
            // 标记是否找到学生编号，默认标记0代表没有找到。
            // 详细逻辑解释：首先初始化Found为假，然后开始for循环，通过if判断来寻找与X值相等的二维表第一列的学号，1.如果找到则执行if中的函数，打印
            //出对应的学号与成绩，并将Found标记为1（真）表示已经找到，随后跳出for循环。2.如果没有找到则不会执行if中的函数，五次for循环依然没有找到相等值之后
            //Found依然保持0(假)，自动跳出for循环经过if(!Found)的判断，为真（1）时运行，为假（0）则跳过，但是这里有！号所以取反，所以这里Found = 0（标记没有找到）
            //时执行if中函数输出“未找到该学生”。
            int Found = 0;
            // 循环查找对应的学号
            for (int i = 0; i < 5; ++i) {
                if(passer[i][0] == X){
                    // 找到后打印对应学号与成绩
                    printf("学号：%d  成绩：%d\n",X,passer[i][1]);
                    // 找到后标记Found = 1表示已找到
                    Found = 1;
                    break;
                }
            }
            if(!Found){
                printf("未找到该学生\n");
            }
        }
    }
}              // 定义函数chaXun进行成绩查询
void SaveGradesToFile() {
    char filename[] = "grades2.txt";// 在打开文件之前定义了一个 filename 字符数组，并在 fopen 之前将文件名赋值给它。可以在需要时使用 filename 来获取文件名。
    FILE *file;// 这是一个变量的定义，表示file是一个指向FILE类型的指针，FILE类型是C语言中用于表示文件的结构体。
    file = fopen(filename, "w" ); // 打开一个文件并以写入模式（w）操作。（如果文件不存在，则会创建文件）

    // 如果file变量等于NULL，说明文件打开失败，就执行大括号里面的语句。
    if (file == NULL) {
        printf("无法打开文件 %s \n", filename);
        return;
    }

    // 将学生成绩数据写入文件
    for (int i = 0; i < MaxStu; ++i) {
        /*
         *这是一个输出语句，表示将passer[i][0]和passeri（两个整数变量，表示第i位学生的学号和成绩）按照"%d %d\n"的格式（两个整数之间有空格，
         *后面有换行符）写入到file指向的文件中。passer是一个二维数组，用于存储所有学生的成绩数据。
         */
        fprintf(file, "%d %d\n", passer[i][0], passer[i][1]);
    }

    fclose(file); // 关闭文件
    printf("学生成绩已保存到文件 %s \n", filename);
}   // 定义函数SaveGradesToFile保存当前二维表内的成绩至grades.txt
void choicePaiXu(){
    int n = 5;  // 表示学生成绩表 passer 中的行数或学生的数量。
    int temp0;  // temp :用于在元素交换时暂时存储元素的值。
    int temp1;
    /*
     这一行定义了几个整数变量，用于在选择排序中的循环和元素交换中使用。
     i 和 j :是循环计数器
     minIndex :用于存储未排序部分的最小元素的索引，
     */
    int i, j, minIndex;

    // 打印提示语：未排序的数组。
    printf("未排序的数组：\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", passer[i][0]);
        printf("%d\n", passer[i][1]);
    }

// ————————————————————————————————————————————————————————————————————————————————————————————————
    for (i = 0; i < n - 1; i++) {
        // 假设当前循环开始时，第一个元素是最小的，从第一个数开始遍历查询对比
        minIndex = i;
        // 在未排序部分找到最小元素的索引
        /*
         如果chengJi[j]中的数小于chengJi[minIndex]中的数，则将minIndex变为j。
         */
        for (j = i + 1; j < n; j++) {
            if (passer[j][1] < passer[minIndex][1]) {
                minIndex = j;
            }
        }

        // 将最小元素与当前位置的元素交换
        temp0 = passer[i][0];// 1.将当前元素的值存储在 temp 中
        temp1 = passer[i][1];
        passer[i][0] = passer[minIndex][0];  // 2.将最小元素的值复制到当前位置
        passer[i][1] = passer[minIndex][1];
        passer[minIndex][0] = temp0;    // 3.将 temp 中的值赋给最小元素的位置。
        passer[minIndex][1] = temp1;
    }
// ————————————————————————————————————————————————————————————————————————————————————————————————
    // 打印提示语：排序后的数组。
    printf("\n排序后的数组：\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", passer[i][0]);
        printf("%d\n", passer[i][1]);
    }
}         // 选择排序
void testAll(){
    // 打印二维数组
    for (int i = 0; i < MaxStu ; ++i) {
        // 打印第0列学号
        printf("%-5d", passer[i][0]);
        // 打印第1列成绩
        printf("%d分\n", passer[i][1]);
    }
}             // test：打印二维数组
void LoadGradesFromFile() {
    char filename[] = "grades2.txt";
    FILE *file;
    file = fopen(filename, "r"); // 打开文件以读取数据

    /*
     * file 是一个文件指针，用于表示打开的文件。
     * if (file == NULL) 是一个判断语句，用于检查文件是否打开成功。
     * 如果 file 等于 NULL，说明文件打开失败，可能是因为文件不存在或者没有权限访问。
     */
    if (file == NULL) {
        printf("无法打开文件 %s \n",filename);
        return;
    }

    for (int i = 0; i < MaxStu; ++i) {
        int studentId, grade;
        // 从文件中读取学号和成绩
        if (fscanf(file, "%d %d", &studentId, &grade) == 2) {
            passer[i][0] = studentId;
            passer[i][1] = grade;
        } else {
            printf("文件格式不合法\n");
            break; // 如果文件格式不合法，退出循环
        }
    }

    fclose(file); //关闭文件
    printf("学生成绩已从文件 %s 读取\n",filename);// %s：输出一个字符串
} // 读取学生成绩
void maoPaoPaiXu(){
    int save1; // 编号
    int save2; // 成绩
    int judge; // 是否完成排序的标记
    for (int i = 0; i < MaxStu - 1 ; ++i) {
        judge = 0; // 已完成排序标记
        for (int j = 0; j < MaxStu - i - 1; ++j) {
            if (passer[j][1] > passer[j + 1][1]){
                save2 = passer[j][1]; // 暂存高成绩学生成绩
                save1 = passer[j][0]; // 暂存高成绩学生学号
                passer[j][1] = passer[j + 1][1]; // 将低成绩学生成绩向上移动覆盖高成绩学生成绩
                passer[j][0] = passer[j + 1][0]; // 将低成绩学生学号向上移动覆盖高成绩学生学号
                passer[j + 1][1] = save2; // 将高成绩学生成绩覆盖在原本低成绩学生成绩上
                passer[j + 1][0] = save1; // 将高成绩学生学号覆盖在原本低成绩学生学号上
                judge = 1; // 未完成排序标记
            }
        }
        if (judge == 0){
            break;
        }
    }
}



int main(){

    do {
        // 调用选项含函数xuanxiang。
        xuanxiang();

        // 使用switch实现项目选择
        // switch解释:根据 choice 变量的值来选择执行哪一个 case 分支。
        switch (choice) {
            case 1:
                printf("1.学生成绩录入\n");
                luRu();// 调用函数luRu用于录入成绩

                break;// break语句用于跳出 switch 语句，防止执行其他 case 的语句。
            case 2:
                printf("2.学生成绩修改\n");
                xiuGai();// 调用函数xiuGai用于修改成绩

                break;
            case 3:
                printf("3.学生成绩删除\n");
                DeleteStuGrades();// 调用DeleteStuGrades用于删除学生成绩
                break;
            case 4:
                printf("4.学生成绩查询\n");
                chaXun();// 调用查询函数chaXun用于查询成绩（循环）

                break;
            case 5:
                printf("5.学生成绩保存\n");
                SaveGradesToFile();// 调用SaveGradesToFile函数保存成绩至grades.txt
                break;

            case 6:
                printf("6.选择排序\n");
                choicePaiXu();
                break;


            case 7:
                printf("7.冒泡排序\n");
                maoPaoPaiXu();
                testAll();
                break;

            case 8:
                printf("8.读取存储的成绩\n");
                LoadGradesFromFile();
                break;

            case 999:
                printf("test：打印目前二维数组\n");
                testAll();// 测试：遍历打印当前数组
                break;


            case 0:
                printf("退出\n");
                // 跳出循环退出程序
                break;

            default:
                printf("无效的选择，请重新选择\n");
        }
        printf("\n");


        // 等待用户按下任意按键
        printf("按下回车键继续...\n");
        getchar();
        getchar(); // 两次 getchar 用于等待用户按下回车键
        // 循环体结束；感叹号 ! 是逻辑运算符，它表示逻辑非（logical NOT）。它的作用是取反，0变1，”真“变“假”。
        // 当choice不等于0时，循环继续执行，否则循环停止。为真（1）时继续循环，为假（0）时停止循环。
    }while (choice !=0);

    return 0;
}