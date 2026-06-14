void ShellSort(int a[],int left,int right){

    int len=right-left+1;

    for(int gap=len/2;gap>0;gap/=2){

        for(int i=left+gap;i<=right;i++){

            int temp=a[i];
            int j=i-gap;

            while(j>=left && a[j]>temp){
                a[j+gap]=a[j];
                j-=gap;
            }

            a[j+gap]=temp;
        }
    }
}
//来自chatgpt的模板^^
