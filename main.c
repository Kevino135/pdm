// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int getYear(){
    int userinput = 0;
    
    scanf("%d", &userinput);
    return userinput;
}

int getTenor(){
    int userinput = 0;
    
    scanf("%d", &userinput);
    return userinput;
}

int getDeposit(){
    float userinput = 0;
    
    scanf("%f", &userinput);
    return userinput;
}

int getinput(char choice[]){
    int input = 0;
    
    if(strcmp(choice, "deposit")){
        input = getDeposit();
    }
    else if(strcmp(choice, "tenor")){
        input = getTenor();
    }
    else if(strcmp(choice, "year")){
        input = getYear();
    }
    
    return input;
}

float calculateTotalBunga(float deposit, int tenor, int year){
    int repetition = (12 / tenor) * year;
    
    float bunga_per_tahun = 0;
    if(tenor == 1) bunga_per_tahun = 0.034;
    else if(tenor == 3) bunga_per_tahun = 0.036;
    else if(tenor == 6) bunga_per_tahun = 0.0375;
    else if(tenor == 12) bunga_per_tahun = 0.042;
    
    float bunga = 0;
    float deposit_total = 0;
    float total_bunga = 0;
    float deposit_rep = deposit;
    for(int i=0; i<repetition; i++){
        printf("Deposit: %.2f\n", deposit_rep);
        bunga = deposit_rep * bunga_per_tahun / 12 * tenor;
        deposit_total = deposit_rep + bunga;
        total_bunga = deposit_total - deposit; 
        
        deposit_rep = deposit_total;
        printf("Bunga: %.2f\n", bunga);
        printf("Deposit total: %.2f\n", deposit_total);
        printf("Total bunga: %.2f\n\n", total_bunga);
    }
    
    return total_bunga;
}

int main() {
    printf("Input deposit: ");
    float deposit = getinput("deposit");
    
    printf("Input tenor: ");
    int tenor = getinput("tenor");
    
    printf("Input year: ");
    int year = getinput("year");
    
    // printf("%d\n", get_input_deposit);
    // printf("%d\n", get_input_tenor);
    // printf("%d\n", get_input_year);
    
    float calculate_total_bunga = calculateTotalBunga(deposit, tenor, year);
    printf("%f\n", calculate_total_bunga);
    
    // int biaya = deduction();
    // int net_investment = netInvestment();

    return 0;
}
