#include <stdio.h>

int call_durations[100];//Create an array to store call duration of about 100 calls

void input_call_duration();
double calculate_cost();

int main(){
    int n;
    double cost;
    printf("\nInput number of calls(MAX_LIMIT=100):- ");
    scanf("%d", &n);
    input_call_duration(n);
    cost = calculate_cost(n);
    printf("\nThe total cost is: %0.2f/-", cost);
}

void input_call_duration(int n){
    int duration, i;
    for(i=0; i<=n-1; i++){
        printf("\n\nInput the duration in minutes for call %d: ", i);
        scanf("%d", &duration);
        call_durations[i] = duration;
    }
}

double calculate_cost(int n){
    int i;
    double cost, gst = 0.05;
    for(i=0;i<=n-1;i++){
        if(call_durations[i]<=2)
            cost = cost + call_durations[i]*10;

        else
            cost = cost + call_durations[i]*8;
    }
    if(cost>1000)
        cost = cost + (cost*gst);

    return cost;
}