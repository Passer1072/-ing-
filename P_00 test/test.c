//#include <stdio.h>

   // 定义函数基本语法
//返回类型 函数名称(参数列表) {
//    // 函数体，包含具体的代码实现
//    // 可以包含局部变量和语句
//    return 返回值; // 返回值类型必须与函数声明的返回类型匹配
//}



// 自定义函数，用于计算两个整数的和
//int Chaxun() {
//    int result = a + b;
//    return Chaxun();
//}
//
//int main() {
//    int num1 = 5;
//    int num2 = 3;
//
//    // 调用自定义函数并将结果存储在变量sum中
//    int sum = add(num1, num2);
//
//    // 打印计算结果
//    printf("和：%d\n", sum);
//
//    return 0;
//}


#include <stdio.h>
// 全局变量
int choice;
int const MaxStu = 5;
int exitFlag = 0; // 控制是否退出的标志，初始为0表示不退出
int passer[5][2]; // 特殊：数组的维度必须是常量表达式

void XuanXiang(){
    // 打印选项
    printf("   菜  单\n");
    printf("1.学生成绩录入\n");
    printf("2.学生成绩修改\n");
    printf("3.学生成绩删除\n");
    printf("4.学生成绩查询\n");
    printf("5.学生成绩保存\n");
    printf("0.退       出\n");
    printf("请输入序号：");
    // scanf 是 C 语言中用于从用户或文件读取输入的函数，它的意思是扫描格式化字符串。
    scanf("%d", &choice);
}           // 定义函数XuanXiang打印全部选项，并保存用户输入的项目编号
void ChaXun(){
int X;
int Y;
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
}              // 定义函数Chaxun进行成绩查询
void LuRu(){
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
}                // 定义函数Luru进行成绩录入。
void XiuGai(){
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
    }              // 定义函数XiuGai进行成绩修改
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
            // 错误示范
//            for (int i = StuNumber; i < MaxStu - 1; ++i) {
//                passer[i][0] = passer[i + 1][0];
//                passer[i][1] = passer[i + 1][1];
            // 清除最后一行的数据
            passer[MaxStu - 1][0] = 0;
            passer[MaxStu - 1][1] = 0;
            printf("删除完成\n");
         }
    }
    // 真假函数判断
    if(!Found){
        printf("未找到该学生\n");
    }
}     // 法一（BUG-已解决）：定音函数DeleteStuGrades进行成绩删除
void DeleteStuGrades2() {
    int StuNumber;
    printf("请输入要删除的学号:");
    scanf("%d", &StuNumber);

    int found = 0; // 用于标记是否找到学生

    for (int i = 0; i < MaxStu; ++i) {
        if (passer[i][0] == StuNumber) {
            found = 1; // 标记为找到学生
            // 删除学号为StuNumber的学生，将后续学生数据依次上移一个位置
            for (int j = i; j < MaxStu - 1; ++j) {
                passer[j][0] = passer[j + 1][0];
                passer[j][1] = passer[j + 1][1];
            }
            // 清除最后一行的数据
            passer[MaxStu - 1][0] = 0;
            passer[MaxStu - 1][1] = 0;
            printf("删除完成\n");
            break;
        }
    }

    if (!found) {
        printf("未找到该学生\n");
    }
}   // 法二：定音函数DeleteStuGrades进行成绩删除
void ChoiceByIf(){
    int X;
    int Y;
    // 用if实现项目选择
        if(choice >= 0 && choice <= 5 ) {
            // 1.学生成绩录入
            if (choice == 1) {
                printf("请输入学生成绩\n");
                // 录入成绩
                for (int i = 0; i < MaxStu ; ++i) {
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
            }

            if (choice == 2) {
                // 2.学生成绩修改
                printf("学生成绩修改\n");
            }
            if (choice == 3) {
                // 3.学生成绩删除
                printf("学生成绩删除\n");
            }
            if (choice == 4) {
                // 4.学生成绩查询
                printf("学生成绩查询\n");
            // 查询命令（循环），!exitFlag为真时继续，为假时退出。
                while (!exitFlag) {
                    printf("输入要查询的编号：");
                    // 从键盘输入存储在X中。
                    scanf("%d", &X );
                    // ==用于判断左右两边
                    if (X == 0){
                        exitFlag = 1;
                    } else {
                        Y = X - 1;
                        // 判断学号是否在1-5的区间中
                        if(Y >= 0 && Y < MaxStu) {
                            // 打印表格中对应值并换行
                            printf("您的成绩：%d\n", passer[Y][1]);
                        }else{
                            printf("无效学号，请重新输入\n");
                        }
                    }
                }
            }
            if (choice == 5) {
                printf("学生成绩保存\n");
            }
            if (choice == X) {
                printf("退出程序");
            }
        } else{
            printf("选择无效，请重新输入\n");
        }
}          // 定义函数ChoiceByIf，项目选择法一：if
void ChoiceByIfelse(){
     // 使用if...else实现项目选择
        if (choice == 1){
            printf("1\n");
        } else if (choice == 2){
            printf("2\n");
        } else if (choice == 3){
            printf("3\n");
        } else if (choice == 4){
            printf("4\n");
        } else if (choice == 5){
            printf("5\n");
        } else if (choice == 0){
            printf(" 结束程序\n");

        } else {
            printf("无效\n") ;
        }
}      // 定义函数ChoiceByIfelse，项目选择法二：if...else
void DaYinZu(){
    // 打印二维数组
    for (int i = 0; i < MaxStu ; ++i) {
        // 打印第0列学号
        printf("%-5d", passer[i][0]);
        // 打印第1列成绩
        printf("%d分\n", passer[i][1]);
    }
}             // test：打印二位数组
void SaveGradesToFile() {
    // 这是一个变量的定义，表示file是一个指向FILE类型的指针，FILE类型是C语言中用于表示文件的结构体。
    FILE *file;
    // 用fopen函数打开一个名为grades.txt的文件，并以写入模式（“w”）打开
    file = fopen("grades.txt", "w"); // 打开一个文件来写入数据（如果文件不存在，则会创建文件）

    // 如果file变量等于NULL，说明文件打开失败，就执行大括号里面的语句。
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }

    // 将学生成绩数据写入文件
    for (int i = 0; i < MaxStu; ++i) {
        // 这是一个输出语句，表示将passer[i][0]和passeri（两个整数变量，表示第i位学生的学号和成绩）按照"%d %d\n"的格式（两个整数之间有空格，
        //后面有换行符）写入到file指向的文件中。passer是一个二维数组，用于存储所有学生的成绩数据。
        fprintf(file, "%d %d\n", passer[i][0], passer[i][1]);
    }

    fclose(file); // 关闭文件
    printf("学生成绩已保存到文件 grades.txt\n");
}   // 定义函数SaveGradesToFile保存当前二维表内的成绩至grades.txt


int main(){

    do {
        // 调用选项含函数XuanXiang。
        XuanXiang();

        // 使用switch实现项目选择
        // switch解释:根据 choice 变量的值来选择执行哪一个 case 分支。
        switch (choice) {
            case 1:
                printf("1.学生成绩录入\n");
               LuRu();// 调用函数Luru用于录入成绩

                break;// break语句用于跳出 switch 语句，防止执行其他 case 的语句。
            case 2:
                printf("2.学生成绩修改\n");
                XiuGai();// 调用函数XiuGai用于修改成绩

                break;
            case 3:
                printf("3.学生成绩删除\n");
                DeleteStuGrades();// 调用DeleteStuGrades用于删除学生成绩
                break;
            case 4:
                printf("4.学生成绩查询\n");
               ChaXun();// 调用查询函数Chaxun用于查询成绩（循环）

                break;
            case 5:
                printf("5.学生成绩保存\n");
                SaveGradesToFile();// 调用SaveGradesToFile函数保存成绩至grades.txt
                break;
            case 6:
                printf("6.test：打印目前二维数组\n");
                DaYinZu();

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

