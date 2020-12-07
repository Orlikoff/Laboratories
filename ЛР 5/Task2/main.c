int Recursive_Multiple(int a, int b, int *massive){
    int mult = 1;
    int current = massive[a];
    int res = pow(current, 2) + cos(current);
    a++;
    mult *= res;
    if(a > b){
        return mult;
    }
    else{
        return Recursive_Multiple(a, b, massive);
    }
}
