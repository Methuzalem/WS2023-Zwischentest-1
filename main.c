#include <stdio.h>
#include <stdlib.h>

double countTax();

int main()
{
    double balance = 100.00; double input; double inputTotal; char typ; double tax; double taxTotal; double payoutTotal; int incomeCount = 0; int payoutCount = 0;

    while(1){
//Guthaben und Eingabemaske für Typ, inkl. Break bei '=' und negativ Betrag überprüfung
    printf("\nGuthaben: %.2f Euro", balance);
    printf("\nTyp: ");
    scanf(" %c", &typ);
    if(typ == '='){
        break;
    }else {
        printf("\nBetrag in Euro: ");
        scanf(" %lf", &input);
    }
    if(input < 0){
        printf("\nDer Betrag kann nicht negativ sein.");
    }
//Steuerfreie Einnahme
        if(typ == 's' && input > 0){
            balance = balance + input;
            inputTotal = inputTotal + input;
            ++ incomeCount;
//Kosten
        }else if(typ == 'k' && input > balance){
            printf("\nDiese Kosten koennen nicht bezahlt werden.");
        }else if(typ == 'k' && input > 0){
            balance = balance - input;
            payoutTotal = payoutTotal + input;
            ++ payoutCount;
//Besteuerte Einnahmen
        }else if(typ == 'e' && input > 0){
            tax = countTax(input);
            input = input - tax;
            taxTotal = taxTotal + tax;
            inputTotal = inputTotal + input;
            balance = balance + input;
            ++ incomeCount;
            printf("\nGezahlte Steuern: %.2lf Euro", tax);
        }
    }
    if(incomeCount == 0 && payoutCount == 0){
            printf("\nRestguthaben: %.2lf Euro", balance);
            printf("\n%d Einnahmen mit durchschnittlichem Wert 0.00 Euro", incomeCount);
            printf("\n%d Ausgaben mit durchschnittlichem Wert 0.00 Euro", payoutCount);
            printf("\nGezahlte Steuern: %.2lf Euro", taxTotal);
    }else if(payoutCount == 0){
            printf("\nRestguthaben: %.2lf Euro", balance);
            printf("\n%d Einnahmen mit durchschnittlichem Wert %.2lf Euro", incomeCount, inputTotal/incomeCount);
            printf("\n%d Ausgaben mit durchschnittlichem Wert 0.00 Euro", payoutCount);
            printf("\nGezahlte Steuern: %.2lf Euro", taxTotal);
    }else if(incomeCount == 0){
            printf("\nRestguthaben: %.2lf Euro", balance);
            printf("\n%d Einnahmen mit durchschnittlichem Wert 0.00 Euro", incomeCount);
            printf("\n%d Ausgaben mit durchschnittlichem Wert %.2lf Euro", payoutCount, payoutTotal/payoutCount);
            printf("\nGezahlte Steuern: %.2lf Euro", taxTotal);
    }else{
            printf("\nRestguthaben: %.2lf Euro", balance);
            printf("\n%d Einnahmen mit durchschnittlichem Wert %.2lf Euro", incomeCount, inputTotal/incomeCount);
            printf("\n%d Ausgaben mit durchschnittlichem Wert %.2lf Euro", payoutCount, payoutTotal/payoutCount);
            printf("\nGezahlte Steuern: %.2lf Euro", taxTotal);
    }
    return 0;
}

double countTax(double input){

double tax;
double taxBig;
double taxPercent;

    if(input > 200){
        taxBig = input - 200;
        taxPercent = taxBig * 0.4;
        tax = 3 + 30 + taxPercent;
    }else if(input > 50 && input <= 200){
        taxBig = input - 50;
        taxPercent = taxBig * 0.2;
        tax = 3 + taxPercent;
    }else if(input > 20 && input <= 50){
        taxBig = input - 20;
        tax = taxBig * 0.1;
    }else{
        tax = 0;
    }
      return tax;
}
