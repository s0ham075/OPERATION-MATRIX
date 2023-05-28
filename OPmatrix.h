#include <stdio.h>
#include <math.h>
#include <stdbool.h>
struct vector{
    int n;
    float value[10];
};
void add_vector(struct vector v1, struct vector v2,float v3[]){
    int flag;
    if(v1.n>=v2.n){
        flag= v1.n;
    }
    else{
        flag= v2.n;
    }
    for(int i =0;i<flag;i++){
        v3[i]=v1.value[i] + v2.value[i];
    }

    return;
}

float dot_product(struct vector v1, struct vector v2){
    int min ;
    float sum =0;
    if(v1.n>=v2.n){
        min = v2.n;
    }
    else{
        min = v1.n;
    }
    for(int i =0;i<min;i++){
        sum+=v1.value[i] * v2.value[i];
    }
    return sum;
} 

void triple_product(struct vector a, struct vector b, struct vector c,float sub[]){
    float x=dot_product(a,c);
    float y=dot_product(a,b);
    for(int i=0;i<b.n;i++){
        b.value[i]=x*b.value[i];
    }
    for(int i=0;i<c.n;i++){
        c.value[i]=y*c.value[i];
    }
    int min; 
    if(c.n>=b.n){
        min = c.n;
    }
    else{
        min = b.n;
    }
    for(int i =0;i<min;i++){
        sub[i]=b.value[i]-c.value[i];
    }
    return ;
}

typedef struct vector3
{
    int x, y, z;
} vector3;


vector3 cross_product(vector3 v1, vector3 v2)
{
    vector3 crossproduct = {0, 0, 0};
    crossproduct.x = v1.y * v2.z - v1.z * v2.y;
    crossproduct.y = v1.x * v2.z - v1.z * v2.x;
    crossproduct.z = v1.x * v2.y - v1.y * v2.x;
    return crossproduct;
}
void mprint(int r,int c, float arr[r][c]){
    for(int i =0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%0.2f  ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    return;
}
void add_mat(int n,int r,int c,float a[r][c]){
    float result[r][c];
    for(int j=0;j<r;j++){
        for(int k=0;k<c;k++){
            a[j][k]=0;
        }
    }
    for(int i=1;i<=n;i++){
        printf("enter matrix %d:\n",i);
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                scanf("%f",&result[j][k]);
                a[j][k]+=result[j][k];
            }
        }
    }
    return;
}

void transpose(int n,int m, float a[n][m],float ans[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=a[j][i];
        }
    }
    return ;
}
void crt(int n,float a[n][n],float b[n-1][n-1],int x,int y){
    float *p = &b[0][0];
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i==x || j==y){
                continue;
            }
            else{
                *p =a[i][j];
                p++;
            }
            
        }
    }
    return;
   
}

void multiply_matrix(int r1, int c1,int c2,float a[r1][c1],float b[c1][c2], float result[r1][c2]){
     for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
            float sum =0;
            for (int k = 0; k < c1; k++){
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

float det(int n, float arr[n][n]){
    if(n==2){
      return (arr[0][0]*arr[1][1])-(arr[1][0]*arr[0][1]);
    }
    int sum =0;
    for(int i =0;i<n;i++){
        float temp [n-1][n-1];
        crt(n,arr,temp,0,i);
        if(i%2==0){
            sum+=arr[0][i]*det(n-1,temp);
        }
        else{
            sum+= (-1)*(arr[0][i]*det(n-1,temp));
        }
    }      
    return sum;
}
void adjoint(int n, float arr[n][n],float ans[n][n]){
    if(n==2){
        ans[0][0]= arr[1][1];
        ans[1][1]=arr[0][0];
        ans[0][1]=(-1)*arr[0][1];
        ans[1][0]=(-1)*arr[1][0];
        return;
    }
    else{
        float y[n][n];
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                float temp [n-1][n-1];
                crt(n,arr,temp,i,j);
                y[i][j]=pow(-1,i+j)*det(n-1,temp);
            }
        }
        transpose(n,n,y,ans);
        return ;
    }
}

void inverse(int n,float a[n][n],float ans[n][n]){
    adjoint(n,a,ans);  
    int x =det(n,a);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]/=x;
        }
    }  
   
    return;
}

void swap(int R, int C,int mat[R][C], int row1, int row2,int col)
{
    for (int i = 0; i < col; i++)
    {
        int temp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}

void linear_eqn(int n,float coef[n][n],float val[n][1],float ans[n][1]){
    float D = det(n,coef);
    bool flag= true;
    for(int i=0;i<n;i++){
        if(val[i][1]!=0){
           flag = false;
                break;
            }
        }
        if(D==0){
            if(flag){
                printf("There exist infinitely many solutions for the given set of linear equations.");
            }
            else{
            printf("No solutions exist for the following set of linear equations.");
            }
            return;
        }
        else{
            if(flag){
                printf("We get trivial solutions as all solutions are 0.");
            }
            else{
                float a[n][n];
                inverse(n,coef,a);
                mprint(n,n,a);
                multiply_matrix(n,n,1,a,val,ans);
            }
        }
    }


int lr(int n,float input[n][2], float arr[2][1]){
    float x[n][2];
    for(int i=0;i<n;i++){
        x[i][0]=1;
        x[i][1]=input[i][0];
    }
    float y[n][1];
    for(int i=0;i<n;i++){
        y[i][0]=input[i][1];
    }
    float xT[2][n];
    transpose( n,2,x,xT);
    float xxT[2][2];
    multiply_matrix(2,n,2,xT,x,xxT);
    float g[2][2];
    inverse(2,xxT,g);
    float h[2][1];
    multiply_matrix(2,n,1,xT,y,h);
    multiply_matrix(2,2,1,g,h,arr);
}
