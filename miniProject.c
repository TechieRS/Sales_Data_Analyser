#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "sales_data.bin"

typedef struct {
    int id;            
    char item[30];     
    float amount;     
} SaleRecord;

void importSalesData();
void calculateMetrics();
void generateReport();

int main() {
    int choice;

    do {
        printf("\nSales Data Analyzer\n");
        printf("1. Import Sales Data\n");
        printf("2. Calculate Metrics\n");
        printf("3. Generate Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: importSalesData(); break;
            case 2: calculateMetrics(); break;
            case 3: generateReport(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void importSalesData() {
    FILE *file = fopen(FILENAME, "ab");
    if (!file) {
        perror("Error opening file");
        return;
    }

    SaleRecord record;
    int n;

    printf("Enter the number of sales records to import: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter details for record %d:\n", i + 1);
        printf("Sale ID: ");
        scanf("%d", &record.id);
        printf("Item Name: ");
        scanf(" %[^\n]", record.item);
        printf("Sale Amount: ");
        scanf("%f", &record.amount);

        fwrite(&record, sizeof(SaleRecord), 1, file);
    }

    fclose(file);
    printf("Sales data imported successfully!\n");
}

void calculateMetrics() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    SaleRecord record;
    float totalSales = 0.0;
    int count = 0;

    while (fread(&record, sizeof(SaleRecord), 1, file) == 1) {
        totalSales += record.amount;
        count++;
    }

    fclose(file);

    if (count > 0) {
        printf("\nMetrics:\n");
        printf("Total Sales: %.2f\n", totalSales);
        printf("Average Sales: %.2f\n", totalSales / count);
    } else {
        printf("No sales data available.\n");
    }
}
void generateReport() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    SaleRecord record;

    printf("\nSales Report:\n");
    printf("ID\tItem Name\t\tAmount\n");
    printf("--------------------------------------\n");

    while (fread(&record, sizeof(SaleRecord), 1, file) == 1) {
        printf("%d\t%-15s\t%.2f\n", record.id, record.item, record.amount);
    }

    fclose(file);
    printf("--------------------------------------\n");
    printf("End of Report.\n");
}
