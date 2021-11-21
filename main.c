// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <math.h>

int getYear(){
    int userinput = 0;
    
    do{
        printf("Input tahun min. 1 tahun & maks. 10 tahun\n");
        printf("Input tahun: ");
        scanf("%d", &userinput);
        getchar();
        
        if(userinput >= 1 && userinput <= 10){
            printf("Tahun valid\n\n");
            break;
        } 
        else printf("Tahun tidak valid\n\n");
    }while(1);
    
    return userinput;
}

int getTenor(){
    int userinput = 0;
    
    do{
        printf("Pilihan tenor yang tersedia antara lain:\n");
        printf("a) 1 bulan\n");
        printf("b) 3 bulan\n");
        printf("c) 6 bulan\n");
        printf("d) 12 bulan\n");
        
        printf("Input tenor sesuai dengan pilihan yang tersedia: ");
        scanf("%d", &userinput);
        getchar();
        
        if(userinput == 1 || userinput == 3 || userinput == 6 || userinput == 12){
            printf("Tenor valid\n\n");
            break;
        } 
        else printf("Tenor tidak valid\n\n");
    }while(1);
    
    return userinput;
}

float getDeposit(){
    float userinput = 0;
    do{
        printf("Nilai deposito awal harus antara [USD$100 - USD$10000]\n");
        printf("Input nilai deposito: ");
        scanf("%f", &userinput);
        getchar();
        
        if(userinput >= 100 && userinput <= 10000){
            printf("Nilai deposito valid\n\n");
            break;
        } 
        else printf("Nilai deposito tidak valid\n\n");
    }while(1);
    
    return userinput;
}

int getinput(char choice[]){
    int input = 0;
    
    if(strcmp(choice, "deposit") == 0){
        input = getDeposit();
    }
    else if(strcmp(choice, "tenor") == 0){
        input = getTenor();
    }
    else if(strcmp(choice, "year") == 0){
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
        // printf("Deposit: %.2f\n", deposit_rep);
        bunga = deposit_rep * bunga_per_tahun / 12 * tenor;
        
        // get only 2 decimal with no rounding
        bunga = floor(bunga * 100) / 100;
        
        deposit_total = deposit_rep + bunga;
        total_bunga = deposit_total - deposit; 
        
        deposit_rep = deposit_total;
        // printf("Bunga: %.2f\n", bunga);
        // printf("Deposit total: %.2f\n", deposit_total);
        // printf("Total bunga: %.2f\n\n", total_bunga);
    }
    
    return total_bunga;
}

float incomeTax(float total_bunga){
    return floor((total_bunga * 0.2) * 100) / 100;
}

float interestExpenses(float total_bunga){
    return floor((total_bunga * 0.01) * 100) / 100;
}

float deduction(float deposit, float total_bunga){
    float interest_expenses = interestExpenses(total_bunga);
    
    if(deposit > 1000){
        return interest_expenses + incomeTax(total_bunga);    
    }
    
    return interest_expenses;
}

float netInvestment(float deposit, float total_bunga, float biaya){
    return deposit + (total_bunga - biaya);
}

int main() {
    float deposit = getinput("deposit");
    int tenor = getinput("tenor");
    int year = getinput("year");
    
    // printf("%d\n", get_input_deposit);
    // printf("%d\n", get_input_tenor);
    // printf("%d\n", get_input_year);
    
    float calculate_total_bunga = calculateTotalBunga(deposit, tenor, year);
    // printf("%.2f\n", calculate_total_bunga);
    
    float biaya = deduction(deposit, calculate_total_bunga);
    // printf("%.2f\n", biaya);
    float net_investment = netInvestment(deposit, calculate_total_bunga, biaya);
    printf("Net Investment: %.2f", net_investment);

    return 0;
}
