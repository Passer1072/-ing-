//#include <stdio.h>

   // ���庯�������﷨
//�������� ��������(�����б�) {
//    // �����壬��������Ĵ���ʵ��
//    // ���԰����ֲ����������
//    return ����ֵ; // ����ֵ���ͱ����뺯�������ķ�������ƥ��
//}



// �Զ��庯�������ڼ������������ĺ�
//int chaXun() {
//    int result = a + b;
//    return chaXun();
//}
//
//int main() {
//    int num1 = 5;
//    int num2 = 3;
//
//    // �����Զ��庯����������洢�ڱ���sum��
//    int sum = add(num1, num2);
//
//    // ��ӡ������
//    printf("�ͣ�%d\n", sum);
//
//    return 0;
//}


#include <stdio.h>
// ȫ�ֱ���
int choice;
int const MaxStu = 5;
int exitFlag = 0; // �����Ƿ��˳��ı�־����ʼΪ0��ʾ���˳�
int passer[5][2]; // ���⣺�����ά�ȱ����ǳ������ʽ

void xuanxiang(){
    // ��ӡѡ��
    printf("   ��  ��\n");
    printf("1.ѧ���ɼ�¼��\n");
    printf("2.ѧ���ɼ��޸�\n");
    printf("3.ѧ���ɼ�ɾ��\n");
    printf("4.ѧ���ɼ���ѯ\n");
    printf("5.ѧ���ɼ�����\n");
    printf("6.ѧ���ɼ�����(����)\n");
    printf("0.��       ��\n");
    printf("��������ţ�");
    // scanf �� C ���������ڴ��û����ļ���ȡ����ĺ�����������˼��ɨ���ʽ���ַ�����
    scanf("%d", &choice);
}           // ���庯��xuanxiang��ӡȫ��ѡ��������û��������Ŀ���
void luRu(){
    // ¼��ɼ�
    for (
            int i = 0; i < MaxStu ; ++i) {
        //�Զ�д���к�
        passer[i][0] = i + 1;
        //�ֶ�����ڶ��гɼ�
        printf("������%dѧ���ɼ���", i + 1);
        scanf("%d", &passer[i][1]);
    }

    // ��ӡ��ά����
    for (int i = 0; i < MaxStu ; ++i) {
        // ��ӡ��0��ѧ��
        printf("%-5d", passer[i][0]);
        // ��ӡ��1�гɼ�
        printf("%d��\n", passer[i][1]);
    }
}                // ���庯��luRu���гɼ�¼�롣
void xiuGai(){
    int StudentID;
    printf("����ѧ�ţ�");
    scanf("%d", &StudentID);

    int found = 0; // ���ڱ���Ƿ��ҵ�ѧ��

    for (int i = 0; i < 5; ++i) {
        if (passer[i][0] == StudentID) {
            printf("�������µĳɼ���");
            scanf("%d", &passer[i][1]);
            found = 1; // ���Ϊ�ҵ�ѧ��
            break; // �ҵ�ѧ�����˳�ѭ��
        }
    }

    if (!found) {
        printf("δ�ҵ���ѧ��\n");
    }
}              // ���庯��xiuGai���гɼ��޸�
void DeleteStuGrades(){
    int StuNumber;
    int Found = 0;
    printf("������Ҫɾ����ѧ��:");
    // ��ȡѧ��
    scanf("%d",&StuNumber);
    // ����Ҫɾ����ѧ��ѧ������
    // ��0�п�ʼ������λ����
    for (int i = 0; i < MaxStu; ++i) {
        // �ж��Ƿ��ҵ�
        if(passer[i][0] == StuNumber){
            // ����ֵ�����ҵ�ѧ��
            Found = 1;
            printf("���ҵ�ѧ��,��ʼɾ��\n");
            // ��Ҫɾ����λ�ÿ�ʼ��������ѧ��������������
            for (int j = i; j < MaxStu - 1; ++j) {
                passer[j][0] = passer[j + 1][0];
                passer[j][1] = passer[j + 1][1];

            }
            // ������һ�е�����
            passer[MaxStu - 1][0] = 0;
            passer[MaxStu - 1][1] = 0;
            printf("ɾ�����\n");

            // ���Ż���ɾ����ɺ�ֱ��break����˳�ѭ��
            break;
        }
    }
    // ��ٺ����ж�
    if(!Found){
        printf("δ�ҵ���ѧ��\n");
    }
}     // ��һ��BUG-�ѽ��������������DeleteStuGrades���гɼ�ɾ��
void chaXun(){
int X;
int exitFlag = 0;
    // while (!exitFlag)Ϊ�棨1��ʱ����ѭ����Ϊ�٣�0��ʱ����ѭ����
    while (!exitFlag) {
        printf("����Ҫ��ѯ�ı�ţ�0�˳�����");
        // �Ӽ�������洢��X�С�
        scanf("%d", &X );
        // ==�����ж��������ߣ��ж�ѡ��X�Ƿ�Ϊ0.
        if (X == 0){
            // �˳�ѭ���ı��
            exitFlag = 1;
        } else {
            // ����Ƿ��ҵ�ѧ����ţ�Ĭ�ϱ��0����û���ҵ���
            // ��ϸ�߼����ͣ����ȳ�ʼ��FoundΪ�٣�Ȼ��ʼforѭ����ͨ��if�ж���Ѱ����Xֵ��ȵĶ�ά���һ�е�ѧ�ţ�1.����ҵ���ִ��if�еĺ�������ӡ
            //����Ӧ��ѧ����ɼ�������Found���Ϊ1���棩��ʾ�Ѿ��ҵ����������forѭ����2.���û���ҵ��򲻻�ִ��if�еĺ��������forѭ����Ȼû���ҵ����ֵ֮��
            //Found��Ȼ����0(��)���Զ�����forѭ������if(!Found)���жϣ�Ϊ�棨1��ʱ���У�Ϊ�٣�0�������������������У�������ȡ������������Found = 0�����û���ҵ���
            //ʱִ��if�к��������δ�ҵ���ѧ������
            int Found = 0;
            // ѭ�����Ҷ�Ӧ��ѧ��
            for (int i = 0; i < 5; ++i) {
                if(passer[i][0] == X){
                    // �ҵ����ӡ��Ӧѧ����ɼ�
                    printf("ѧ�ţ�%d  �ɼ���%d\n",X,passer[i][1]);
                    // �ҵ�����Found = 1��ʾ���ҵ�
                    Found = 1;
                    break;
                }
            }
            if(!Found){
                printf("δ�ҵ���ѧ��\n");
            }
        }
    }
}              // ���庯��chaXun���гɼ���ѯ
void SaveGradesToFile() {
    // ����һ�������Ķ��壬��ʾfile��һ��ָ��FILE���͵�ָ�룬FILE������C���������ڱ�ʾ�ļ��Ľṹ�塣
    FILE *file;
    // ��fopen������һ����Ϊgrades.txt���ļ�������д��ģʽ����w������
    file = fopen("grades.txt", "w"); // ��һ���ļ���д�����ݣ�����ļ������ڣ���ᴴ���ļ���

    // ���file��������NULL��˵���ļ���ʧ�ܣ���ִ�д������������䡣
    if (file == NULL) {
        printf("�޷����ļ�\n");
        return;
    }

    // ��ѧ���ɼ�����д���ļ�
    for (int i = 0; i < MaxStu; ++i) {
        // ����һ�������䣬��ʾ��passer[i][0]��passeri������������������ʾ��iλѧ����ѧ�źͳɼ�������"%d %d\n"�ĸ�ʽ����������֮���пո�
        //�����л��з���д�뵽fileָ����ļ��С�passer��һ����ά���飬���ڴ洢����ѧ���ĳɼ����ݡ�
        fprintf(file, "%d %d\n", passer[i][0], passer[i][1]);
    }

    fclose(file); // �ر��ļ�
    printf("ѧ���ɼ��ѱ��浽�ļ� grades.txt\n");
}   // ���庯��SaveGradesToFile���浱ǰ��ά���ڵĳɼ���grades.txt
void choicePaiXu(){
    int n = 5;  // ��ʾѧ���ɼ��� passer �е�������ѧ����������
    int temp0;  // temp :������Ԫ�ؽ���ʱ��ʱ�洢Ԫ�ص�ֵ��
    int temp1;
    /*
     ��һ�ж����˼�������������������ѡ�������е�ѭ����Ԫ�ؽ�����ʹ�á�
     i �� j :��ѭ��������
     minIndex :���ڴ洢δ���򲿷ֵ���СԪ�ص�������
     */
    int i, j, minIndex;

    // ��ӡ��ʾ�δ��������顣
    printf("δ��������飺\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", passer[i][0]);
        printf("%d\n", passer[i][1]);
    }

// ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
    for (i = 0; i < n - 1; i++) {
        // ���赱ǰѭ����ʼʱ����һ��Ԫ������С�ģ��ӵ�һ������ʼ������ѯ�Ա�
        minIndex = i;
        // ��δ���򲿷��ҵ���СԪ�ص�����
        /*
         ���chengJi[j]�е���С��chengJi[minIndex]�е�������minIndex��Ϊj��
         */
        for (j = i + 1; j < n; j++) {
            if (passer[j][1] < passer[minIndex][1]) {
                minIndex = j;
            }
        }

        // ����СԪ���뵱ǰλ�õ�Ԫ�ؽ���
        temp0 = passer[i][0];// 1.����ǰԪ�ص�ֵ�洢�� temp ��
        temp1 = passer[i][1];
        passer[i][0] = passer[minIndex][0];  // 2.����СԪ�ص�ֵ���Ƶ���ǰλ��
        passer[i][1] = passer[minIndex][1];
        passer[minIndex][0] = temp0;    // 3.�� temp �е�ֵ������СԪ�ص�λ�á�
        passer[minIndex][1] = temp1;
    }
// ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
    // ��ӡ��ʾ����������顣
    printf("\n���������飺\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", passer[i][0]);
        printf("%d\n", passer[i][1]);
    }
}         // ѡ������
void DeleteStuGrades2() {
    int StuNumber;
    printf("������Ҫɾ����ѧ��:");
    scanf("%d", &StuNumber);

    int found = 0; // ���ڱ���Ƿ��ҵ�ѧ��

    for (int i = 0; i < MaxStu; ++i) {
        if (passer[i][0] == StuNumber) {
            found = 1; // ���Ϊ�ҵ�ѧ��
            // ɾ��ѧ��ΪStuNumber��ѧ����������ѧ��������������һ��λ��
            for (int j = i; j < MaxStu - 1; ++j) {
                passer[j][0] = passer[j + 1][0];
                passer[j][1] = passer[j + 1][1];
            }
            // ������һ�е�����
            passer[MaxStu - 1][0] = 0;
            passer[MaxStu - 1][1] = 0;
            printf("ɾ�����\n");
            break;
        }
    }

    if (!found) {
        printf("δ�ҵ���ѧ��\n");
    }
}   // ��������������DeleteStuGrades���гɼ�ɾ��
void ChoiceByIf(){
    int X;
    int Y;
    // ��ifʵ����Ŀѡ��
        if(choice >= 0 && choice <= 5 ) {
            // 1.ѧ���ɼ�¼��
            if (choice == 1) {
                printf("������ѧ���ɼ�\n");
                // ¼��ɼ�
                for (int i = 0; i < MaxStu ; ++i) {
                    //�Զ�д���к�
                    passer[i][0] = i + 1;
                    //�ֶ�����ڶ��гɼ�
                    printf("������%dѧ���ɼ���", i + 1);
                    scanf("%d", &passer[i][1]);
                }
                // ��ӡ��ά����
                for (int i = 0; i < MaxStu ; ++i) {
                    // ��ӡ��0��ѧ��
                    printf("%-5d", passer[i][0]);
                    // ��ӡ��1�гɼ�
                    printf("%d��\n", passer[i][1]);
                }
            }

            if (choice == 2) {
                // 2.ѧ���ɼ��޸�
                printf("ѧ���ɼ��޸�\n");
            }
            if (choice == 3) {
                // 3.ѧ���ɼ�ɾ��
                printf("ѧ���ɼ�ɾ��\n");
            }
            if (choice == 4) {
                // 4.ѧ���ɼ���ѯ
                printf("ѧ���ɼ���ѯ\n");
            // ��ѯ���ѭ������!exitFlagΪ��ʱ������Ϊ��ʱ�˳���
                while (!exitFlag) {
                    printf("����Ҫ��ѯ�ı�ţ�");
                    // �Ӽ�������洢��X�С�
                    scanf("%d", &X );
                    // ==�����ж���������
                    if (X == 0){
                        exitFlag = 1;
                    } else {
                        Y = X - 1;
                        // �ж�ѧ���Ƿ���1-5��������
                        if(Y >= 0 && Y < MaxStu) {
                            // ��ӡ����ж�Ӧֵ������
                            printf("���ĳɼ���%d\n", passer[Y][1]);
                        }else{
                            printf("��Чѧ�ţ�����������\n");
                        }
                    }
                }
            }
            if (choice == 5) {
                printf("ѧ���ɼ�����\n");
            }
            if (choice == X) {
                printf("�˳�����");
            }
        } else{
            printf("ѡ����Ч������������\n");
        }
}          // ���庯��ChoiceByIf����Ŀѡ��һ��if
void ChoiceByIfelse(){
     // ʹ��if...elseʵ����Ŀѡ��
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
            printf(" ��������\n");

        } else {
            printf("��Ч\n") ;
        }
}      // ���庯��ChoiceByIfelse����Ŀѡ�񷨶���if...else
void testAll(){
    // ��ӡ��ά����
    for (int i = 0; i < MaxStu ; ++i) {
        // ��ӡ��0��ѧ��
        printf("%-5d", passer[i][0]);
        // ��ӡ��1�гɼ�
        printf("%d��\n", passer[i][1]);
    }
}             // test����ӡ��ά����


int main(){

    do {
        // ����ѡ�����xuanxiang��
        xuanxiang();

        // ʹ��switchʵ����Ŀѡ��
        // switch����:���� choice ������ֵ��ѡ��ִ����һ�� case ��֧��
        switch (choice) {
            case 1:
                printf("1.ѧ���ɼ�¼��\n");
               luRu();// ���ú���luRu����¼��ɼ�

                break;// break����������� switch ��䣬��ִֹ������ case ����䡣
            case 2:
                printf("2.ѧ���ɼ��޸�\n");
                xiuGai();// ���ú���xiuGai�����޸ĳɼ�

                break;
            case 3:
                printf("3.ѧ���ɼ�ɾ��\n");
                DeleteStuGrades();// ����DeleteStuGrades����ɾ��ѧ���ɼ�
                break;
            case 4:
                printf("4.ѧ���ɼ���ѯ\n");
               chaXun();// ���ò�ѯ����chaXun���ڲ�ѯ�ɼ���ѭ����

                break;
            case 5:
                printf("5.ѧ���ɼ�����\n");
                SaveGradesToFile();// ����SaveGradesToFile��������ɼ���grades.txt
                break;

            case 6:
                printf("7.ѡ������\n");
                choicePaiXu();
                break;

            case 999:
                printf("test����ӡĿǰ��ά����\n");
                testAll();// ���ԣ�������ӡ��ǰ����
                break;


            case 0:
                printf("�˳�\n");
                // ����ѭ���˳�����
                break;

            default:
                printf("��Ч��ѡ��������ѡ��\n");
        }
        printf("\n");


        // �ȴ��û��������ⰴ��
        printf("���»س�������...\n");
        getchar();
        getchar(); // ���� getchar ���ڵȴ��û����»س���
        // ѭ�����������̾�� ! ���߼������������ʾ�߼��ǣ�logical NOT��������������ȡ����0��1�����桰�䡰�١���
        // ��choice������0ʱ��ѭ������ִ�У�����ѭ��ֹͣ��Ϊ�棨1��ʱ����ѭ����Ϊ�٣�0��ʱֹͣѭ����
    }while (choice !=0);

    return 0;
}

