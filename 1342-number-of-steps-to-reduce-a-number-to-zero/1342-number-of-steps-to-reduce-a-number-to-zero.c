int numberOfSteps(int num) {
    int num_of_steps=0;

    while(num>0)
    {
        if(num%2==0)
        {
            num=num/2;
            num_of_steps++;
        }
        else
        {
            num=num-1;
            num_of_steps++;
        }
    }
   return num_of_steps;
}