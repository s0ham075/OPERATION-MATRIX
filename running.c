#include <stdio.h>
#include <OPmatrix.h>
void add_vector_call(){
    int flag;
    struct vector a;
    struct vector b;
    for(int i=0;i<10;i++){
        a.value[i]=0;
    }
    for(int i=0;i<10;i++){
        b.value[i]=0;
    }
    printf("Enter the dimension of first vector-->");
    scanf("%d",&a.n);
    printf("\nEnter the values of first vector-->");
    for(int i =0;i<a.n;i++){
        scanf("%f",&a.value[i]);
    }
    printf("\nEnter the dimension of second vector-->");
    scanf("%d",&b.n);
    printf("\nEnter the values of second vector-->");
    for(int i =0;i<b.n;i++){
        scanf("%f",&b.value[i]);
    }
    if(b.n>=a.n){
        flag = b.n;
    }
    else{
        flag = a.n;
    }
    float c[flag];
    add_vector(a,b,c);
    for(int i =0;i<flag;i++){
        printf("%0.2f ",c[i]);
    }
}  
void dotproduct_call(){
    struct vector a;
    struct vector b;
    printf("Enter the dimension of first vector-->");
    scanf("%d",&a.n);
    printf("\nEnter the values of first vector-->");
    for(int i =0;i<a.n;i++){
        scanf("%f",&a.value[i]);
    }
    printf("\nEnter the dimension of second vector-->");
    scanf("%d",&b.n);
    printf("\nEnter the values of second vector-->");
    for(int i =0;i<b.n;i++){
        scanf("%f",&b.value[i]);
    }
    printf("Dot product of the given product is --> %0.2f",dot_product(a,b));
} 

void tripleproduct_call(){
    struct vector a;
    struct vector b;
    struct vector c;
    for(int i=0;i<10;i++){
        a.value[i]=0;
    }
    for(int i=0;i<10;i++){
        b.value[i]=0;
    }
    for(int i=0;i<10;i++){
        c.value[i]=0;
    }
    printf("Enter the dimension of first vector-->");
    scanf("%d",&a.n);
    printf("\nEnter the values of first vector-->");
    for(int i =0;i<a.n;i++){
        scanf("%f",&a.value[i]);
    }
    printf("\nEnter the dimension of second vector-->");
    scanf("%d",&b.n);
    printf("\nEnter the values of second vector-->");
    for(int i =0;i<b.n;i++){
        scanf("%f",&b.value[i]);
    }
    printf("\nEnter the dimension of third vector-->");
    scanf("%d",&c.n);
    printf("\nEnter the values of third vector-->");
    for(int i =0;i<c.n;i++){
        scanf("%f",&c.value[i]);
    }
    int min;
    if(c.n>=b.n){
        min = c.n;
    }
    else{
        min = b.n;
    }
    float sub[min];
    triple_product(a,b,c,sub);
    for(int i=0;i<min;i++){
        printf("%0.2f ",sub[i]);
    }
}

void cross_product_call(){
    vector3 v1 = {0, 0, 0};
    vector3 v2 = {0, 0, 0};
    printf("Vector 1 - Enter value for x: ");
    scanf("%d", &v1.x);
    printf("Vector 1 - Enter value for y: ");
    scanf("%d", &v1.y);
    printf("Vector 1 - Enter value for z: ");
    scanf("%d", &v1.z);

    printf("Vector 2 - Enter value for x: ");
    scanf("%d", &v2.x);
    printf("Vector 2 - Enter value for y: ");
    scanf("%d", &v2.y);
    printf("Vector 2 - Enter value for z: ");
    scanf("%d", &v2.z);

    vector3 cp = cross_product(v1, v2);
    printf("Crossproduct: x:%d y:%d z:%d", cp.x, cp.y, cp.z);
}

void add_call(){
    int n;
    printf("enter number of matrices to add-->\n");
    scanf("%d",&n);
    int r;
    printf("Enter the number of rows in matrix-->\n");
    scanf("%d",&r);
    int c;
    printf("Enter the number of columns in matrix-->\n");
    scanf("%d",&c);
    float a[r][c];
    add_mat(n,r,c,a);
    printf("\nThe resultant matrix is- \n");
    for (int j = 0; j < r; j++){
        for (int k = 0; k < c; k++){
            printf("%0.2f \t", a[j][k]);
        }
        printf("\n");
    }
    return;
}
void transpose_call(){
    int m,n;
    printf("Enter the row of matrix-\n");
    scanf("%d",&m);
    printf("Enter the column of matrix-\n");
    scanf("%d",&n);
    float arr[m][n];
    printf("Enter the matrix-\n");
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%f",&arr[i][j]);
        }
    }
    float ans[n][m];
    transpose(m,n,arr,ans);
    printf("\nThe transpose matrix is-\n");
     for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%0.2f \t",ans[i][j]);
        }
        printf("\n");
    }
}
void multiply_call(){
    int r1,c1,r2,c2;
    printf("Enter the number of rows in first matrix:");
    scanf("%d",&r1);
    printf("Enter the number of columns in first matrix:");
    scanf("%d",&c1);
    float a[r1][c1];
    printf("Enter the first matrix:\n");
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            scanf("%f", &a[i][j]);
        }
    }
    printf("Enter the number of rows in second matrix:");
    scanf("%d",&r2);
    printf("Enter the number of coloumns in second matrix:");
    scanf("%d",&c2);
    float b[r2][c2];
    printf("Enter the second matrix:\n");
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            scanf("%f", &b[i][j]);
        }
    }
    if(c1!=r2){
        printf("\nThe matrix cannnot be multiplied");
    }
    else{
        printf("\nthe resultant matrix is:\n");
        float result[r1][c2];
        multiply_matrix(r1,c1,c2,a,b,result);
        for (int i = 0; i < r1; i++){
            for (int j = 0; j < c2; j++){
               printf("%0.2f \t", result[i][j]);
            }
            printf("\n");
        }
    }
}
int det_call(){
    int n;
    printf("Enter the dimension of the matrix-\n");
    scanf("%d",&n);
    float arr[n][n];
    printf("Enter the matrix-\n");
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%f",&arr[i][j]);
        }
    }
    printf("\nThe determinant of matrix is-  %0.2f",det(n,arr));
}

void inverse_call(){
    int n;
    printf("Enter the dimension of the matrix-\n");
    scanf("%d",&n);
    float arr[n][n];
    float a[n][n];
    printf("Enter the matrix-\n");
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%f",&arr[i][j]);
        }
    }
    if(det(n,arr)==0){
        printf("The input matrix is not invertible");
    }
    inverse(n,arr,a);
    printf("\nThe inverse matrix is-\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%0.2f \t",a[i][j]);
        }
        printf("\n");
    }
    return ;
}

void adjoint_call(){
    int n;
    printf("Enter the dimension of the matrix-\n");
    scanf("%d",&n);
    float arr[n][n];
    float a[n][n];
    printf("Enter the matrix-\n");
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%f",&arr[i][j]);
        }
    }
    adjoint(n,arr,a);
    printf("\nThe adjoint matrix is-\n");
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%0.2f \t",a[i][j]);
        }
        printf("\n");
    }

}
void lr_call(){
    printf("Enter the number of data points you have\n");
    int n;
    scanf("%d",&n);
    float input[n][2];
    printf("Enter the input data points\n");
    for(int i=0;i<n;i++){
        scanf("%f %f",&input[i][0],&input[i][1]);
    }
    float ans[2][1];
    lr(n,input,ans);
    printf("\nthe value of slope is- %0.2f ",ans[1][0]);
    printf("\nthe value of constant is- %0.2f ",ans[0][0]);
}

void linear_eqn_call(){
    printf("enter the order of matrix: \n");
    int n;
    scanf("%d",&n);
    float coef[n][n];
    float val[n][1];
    printf("Enter the coefficients in proper manner-\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%f",&coef[i][j]);
        }
    }
    printf("\n");
    printf("Enter the constant terms in proper order-\n");
    for(int i =0;i<n;i++){
        scanf("%f",&val[i][0]);
    }
    float ans[n][1];
    linear_eqn(n,coef,val,ans);
    printf("The solutions of the system of equation are - \n");
    for(int i =0;i<n;i++){
        printf("%0.2f ",ans[i][0]);
    }
    return;
}
int main() {
    printf("\n");
    printf("\n");
    printf("\033[1;32m"); 
    printf("Welcome to the program to demonstrate the  Linear Algebra Header File!\n");
    printf("\033[0m");
    printf("\n");
    printf("\n");
    printf("This program does the following -\n");
    printf("\n");
    printf("   \033[33m1] ADDING VECTORS -\n");
    printf("   \033[33m2] DOT PRODUCT OF TWO VECTORS\n");
    printf("   \033[33m3] TRIPLE PRODUCT OF TWO VECTORS\n");
    printf("   \033[33m4] CROSS PRODUCT OF TWO VECTORS\n");
    printf("   \033[33m5] ADDITION OF MATRIX\n");
    printf("   \033[33m6] TRANSPOSE OF MATRIX\n");
    printf("   \033[33m7] MULTIPLICATION OF TWO MATRIX\n");
    printf("   \033[33m8] DETERMINANT OF MATRIX\n");
    printf("   \033[33m9] ADJOINT OF MATRIX\n");
    printf("  \033[33m10] INVERSE OF MATRIX\n");
    printf("  \033[33m11] LINEAR EQUATION SOLVER\n");
    printf("  \033[33m12] SIMPLE MODELING OF LINEAR REGRESSION\n");
    printf("\033[0m");
    printf("\n");
    printf("\n");
    printf("Enter the serial number to do the respective operation-\n ");
    int n;
    scanf("%d",&n);
    if(n==1){
        add_vector_call();
    }
    else if(n==2){
        dotproduct_call();
    }
    else if(n==3){
        tripleproduct_call();
    }
    else if(n==4){
        cross_product_call();
    }
    else if(n==5){
        add_call();
    }
    else if(n==6){
       transpose_call();
    }
    else if(n==7){
        multiply_call();
    }
    else if(n==8){
       det_call();
    }
    else if(n==9){ 
       adjoint_call();
    }
    else if(n==10){
       inverse_call();
    }
    else if(n==11){
       linear_eqn_call();
    }
    else if(n==12){
       lr_call();
    }


    return 0;
}