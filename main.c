#include <stdio.h>
// ȫ�ֱ���
int choice;
int const MaxStu = 5;
int passer[5][2]; // ���⣺�����ά�ȱ����ǳ������ʽ


void xuanxiang(){
    // ��ӡѡ��
    printf("   ��  ��\n");
    printf("1.ѧ���ɼ�¼��\n");
    printf("2.ѧ���ɼ��޸�\n");
    printf("3.ѧ���ɼ�ɾ��\n");
    printf("4.ѧ���ɼ���ѯ\n");
    printf("5.ѧ���ɼ�����\n");
    printf("6.ѧ���ɼ�����(ѡ��)\n");
    printf("7.ѧ���ɼ�����(ð��)\n");
    printf("8.ѧ���ɼ�����(����)\n");
    printf("9.��ȡ�洢�ĳɼ�\n");
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
    char filename[] = "grades2.txt";// �ڴ��ļ�֮ǰ������һ�� filename �ַ����飬���� fopen ֮ǰ���ļ�����ֵ��������������Ҫʱʹ�� filename ����ȡ�ļ�����
    FILE *file;// ����һ�������Ķ��壬��ʾfile��һ��ָ��FILE���͵�ָ�룬FILE������C���������ڱ�ʾ�ļ��Ľṹ�塣
    file = fopen(filename, "w" ); // ��һ���ļ�����д��ģʽ��w��������������ļ������ڣ���ᴴ���ļ���

    // ���file��������NULL��˵���ļ���ʧ�ܣ���ִ�д������������䡣
    if (file == NULL) {
        printf("�޷����ļ� %s \n", filename);
        return;
    }

    // ��ѧ���ɼ�����д���ļ�
    for (int i = 0; i < MaxStu; ++i) {
        /*
         *����һ�������䣬��ʾ��passer[i][0]��passeri������������������ʾ��iλѧ����ѧ�źͳɼ�������"%d %d\n"�ĸ�ʽ����������֮���пո�
         *�����л��з���д�뵽fileָ����ļ��С�passer��һ����ά���飬���ڴ洢����ѧ���ĳɼ����ݡ�
         */
        fprintf(file, "%d %d\n", passer[i][0], passer[i][1]);
    }

    fclose(file); // �ر��ļ�
    printf("ѧ���ɼ��ѱ��浽�ļ� %s \n", filename);
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
void testAll(){
    printf("ѧ��  �ɼ�\n");
    // ��ӡ��ά����
    for (int i = 0; i < MaxStu ; ++i) {
        // ��ӡ��0��ѧ��
        printf("%-5d", passer[i][0]);
        // ��ӡ��1�гɼ�
        printf("%d��\n", passer[i][1]);
    }
}             // test����ӡ��ά����
void LoadGradesFromFile() {
    char filename[] = "grades2.txt";
    FILE *file;
    file = fopen(filename, "r"); // ���ļ��Զ�ȡ����

    /*
     * file ��һ���ļ�ָ�룬���ڱ�ʾ�򿪵��ļ���
     * if (file == NULL) ��һ���ж���䣬���ڼ���ļ��Ƿ�򿪳ɹ���
     * ��� file ���� NULL��˵���ļ���ʧ�ܣ���������Ϊ�ļ������ڻ���û��Ȩ�޷��ʡ�
     */
    if (file == NULL) {
        printf("�޷����ļ� %s \n",filename);
        return;
    }

    for (int i = 0; i < MaxStu; ++i) {
        int studentId, grade;
        // ���ļ��ж�ȡѧ�źͳɼ�
        if (fscanf(file, "%d %d", &studentId, &grade) == 2) {
            passer[i][0] = studentId;
            passer[i][1] = grade;
        } else {
            printf("�ļ���ʽ���Ϸ�\n");
            break; // ����ļ���ʽ���Ϸ����˳�ѭ��
        }
    }

    fclose(file); //�ر��ļ�
    printf("ѧ���ɼ��Ѵ��ļ� %s ��ȡ\n",filename);// %s�����һ���ַ���
} // ��ȡѧ���ɼ�
void maoPaoPaiXu(){
    int save1; // ���
    int save2; // �ɼ�
    int judge; // �Ƿ��������ı��
    for (int i = 0; i < MaxStu - 1 ; ++i) {
        judge = 0; // �����������
        for (int j = 0; j < MaxStu - i - 1; ++j) {
            if (passer[j][1] > passer[j + 1][1]){
                save2 = passer[j][1]; // �ݴ�߳ɼ�ѧ���ɼ�
                save1 = passer[j][0]; // �ݴ�߳ɼ�ѧ��ѧ��
                passer[j][1] = passer[j + 1][1]; // ���ͳɼ�ѧ���ɼ������ƶ����Ǹ߳ɼ�ѧ���ɼ�
                passer[j][0] = passer[j + 1][0]; // ���ͳɼ�ѧ��ѧ�������ƶ����Ǹ߳ɼ�ѧ��ѧ��
                passer[j + 1][1] = save2; // ���߳ɼ�ѧ���ɼ�������ԭ���ͳɼ�ѧ���ɼ���
                passer[j + 1][0] = save1; // ���߳ɼ�ѧ��ѧ�Ÿ�����ԭ���ͳɼ�ѧ��ѧ����
                judge = 1; // δ���������
            }
        }
        if (judge == 0){
            break;
        }
    }
}         // ð������
void chaRuPaiXu() {
    int temp1;                                      // �洢�ɼ�
    int temp2;                                      // �洢ѧ��
    int j;

    for (int i = 1; i < MaxStu; ++i) {              // ��ѭ��������ά��
        temp1 = passer[i][1];                       // ����ɼ�
        temp2 = passer[i][0];                       // �洢ѧ��
        j = i - 1;                                  // ��ʾ��������Ĳ����е�ǰһ��Ԫ�ص�������

        while (j >= 0 && passer[j][1] > temp1) {    //
            passer[j + 1][1] = passer[j][1];        // �������򲿷��еĽϴ�ɼ������ƶ�һλ��Ϊ temp �ڳ�λ��
            passer[j + 1][0] = passer[j][0];
            j = j - 1;                               // ֵ�ݼ����Ա��������򲿷��м������ϱȽ�
        }

        passer[j + 1][1] = temp1;                   //  �� while ѭ������ʱ��j �Ѿ��ҵ��� temp Ӧ�ò����λ�ã���һ�н� temp ��ֵ���뵽��ȷ��λ�ã�����˲��������
        passer[j + 1][0] = temp2;
    }
}         // ��������

  
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
                printf("6.ѡ������\n");
                choicePaiXu();
                break;


            case 7:
                printf("7.ð������\n");
                maoPaoPaiXu();
                testAll();
                break;

            case 8:
                printf("8.��������\n");
                chaRuPaiXu();
                testAll();
                break;

            case 9:

                printf("9.��ȡ�洢�ĳɼ�\n");
                LoadGradesFromFile();
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