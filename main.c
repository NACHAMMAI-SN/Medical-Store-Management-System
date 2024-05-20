#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for Medicine, Customer, and Supplier
struct Medicine {
    char name[100];
    float price;
    int quantity;
};

struct Customer {
    char name[100];
    int id;
    char number[20];
};

struct Supplier {
    char name[100];
    int id;
    char city[100];
};

FILE*file=NULL;
FILE*tempFile=NULL;
FILE *billFile=NULL;

// Function to add medicine to the medicine file
void addMedicine() {
    struct Medicine medicine;
    file = fopen("medicine.txt", "a");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    printf("Enter medicine name: ");
    scanf("%s", medicine.name);
    printf("Enter price: ");
    scanf("%f", &medicine.price);
    printf("Enter quantity: ");
    scanf("%d", &medicine.quantity);

    fprintf(file, "%-30s %.2f %d\n", medicine.name, medicine.price, medicine.quantity);
    fclose(file);
}

// Function to display medicine from the medicine file
void displayMedicine() {
    struct Medicine medicine;
    file = fopen("medicine.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    printf("\nMedicine List:\n");
    printf("Medicine Name                    Price   Quantity\n");
    while (fscanf(file, "%s %f %d", medicine.name, &medicine.price, &medicine.quantity) != EOF) {
        printf("%-30s %.2f    %d\n", medicine.name, medicine.price, medicine.quantity);
    }
    fclose(file);
}

// Function to modify medicine in the medicine file
void modifyMedicine() {
    char medicineName[100];
    printf("Enter the name of the medicine to modify: ");
    scanf("%s", medicineName);

    struct Medicine medicine;
    file = fopen("medicine.txt", "r");
    tempFile = fopen("temp_medicine.txt", "w");

    int found = 0;
    while (fscanf(file, "%s %f %d", medicine.name, &medicine.price, &medicine.quantity) != EOF) {
        if (strcmp(medicine.name, medicineName) == 0) {
            found = 1;
            printf("Enter new price: ");
            scanf("%f", &medicine.price);
            printf("Enter new quantity: ");
            scanf("%d", &medicine.quantity);
        }
        fprintf(tempFile, "%-30s %.2f %d\n", medicine.name, medicine.price, medicine.quantity);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("Medicine not found.\n");
    } else {
        remove("medicine.txt");
        rename("temp_medicine.txt", "medicine.txt");
        printf("Medicine modified successfully.\n");
    }
}
// Function to add a customer to the customer file
void addCustomer() {
    struct Customer customer;
    file = fopen("customer.txt", "a");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    printf("Enter customer name: ");
    scanf("%s", customer.name);
    printf("Enter customer ID: ");
    scanf("%d", &customer.id);
    printf("Enter customer number: ");
    scanf("%s", customer.number);

    fprintf(file, "%-30s %d %s\n", customer.name, customer.id, customer.number);
    fclose(file);
}

// Function to display customers from the customer file
void displayCustomers() {
    struct Customer customer;
    file = fopen("customer.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    printf("\nCustomer List:\n");
    printf("Name                          ID      Number\n");
    while (fscanf(file, "%s %d %s", customer.name, &customer.id, customer.number) != EOF) {
        printf("%-30s %d       %s\n", customer.name, customer.id, customer.number);
    }
    fclose(file);
}

// Function to modify a customer in the customer file
void modifyCustomer() {
    int customerId;
    printf("Enter the ID of the customer to modify: ");
    scanf("%d", &customerId);

    struct Customer customer;
    file = fopen("customer.txt", "r");
    tempFile = fopen("temp_customer.txt", "w");

    int found = 0;
    while (fscanf(file, "%s %d %s", customer.name, &customer.id, customer.number) != EOF) {
        if (customer.id == customerId) {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", customer.name);
            printf("Enter new number: ");
            scanf("%s", customer.number);
        }
        fprintf(tempFile, "%-30s %d %s\n", customer.name, customer.id, customer.number);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("Customer not found.\n");
    } else {
        remove("customer.txt");
        rename("temp_customer.txt", "customer.txt");
        printf("Customer modified successfully.\n");
    }
}


// Function to add a supplier to the supplier file
void addSupplier() {
    struct Supplier supplier;
    file = fopen("supplier.txt", "a");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    printf("Enter supplier name: ");
    scanf("%s", supplier.name);
    printf("Enter supplier ID: ");
    scanf("%d", &supplier.id);
    printf("Enter supplier city: ");
    scanf("%s", supplier.city);

    fprintf(file, "%-30s %d %s\n", supplier.name, supplier.id, supplier.city);
    fclose(file);
}
// Function to display suppliers from the supplier file
void displaySuppliers() {
    struct Supplier supplier;
    file = fopen("supplier.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    printf("\nSupplier List:\n");
    printf("Name                          ID      City\n");
    while (fscanf(file, "%s %d %s", supplier.name, &supplier.id, supplier.city) != EOF) {
        printf("%-30s %d       %s\n", supplier.name, supplier.id, supplier.city);
    }
    fclose(file);
}
// Function to modify a supplier in the supplier file
void modifySupplier() {
    int supplierId;
    printf("Enter the ID of the supplier to modify: ");
    scanf("%d", &supplierId);

    struct Supplier supplier;
    file = fopen("supplier.txt", "r");
    tempFile = fopen("temp_supplier.txt", "w");

    int found = 0;
    while (fscanf(file, "%s %d %s", supplier.name, &supplier.id, supplier.city) != EOF) {
        if (supplier.id == supplierId) {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", supplier.name);
            printf("Enter new city: ");
            scanf("%s", supplier.city);
        }
        fprintf(tempFile, "%-30s %d %s\n", supplier.name, supplier.id, supplier.city);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("Supplier not found.\n");
    } else {
        remove("supplier.txt");
        rename("temp_supplier.txt", "supplier.txt");
        printf("Supplier modified successfully.\n");
    }
}
// Function to generate a bill for a customer
void generateBillForCustomer() {
    billFile = fopen("bills.txt", "a");
    if (billFile == NULL) {
        printf("Error opening bill file");
        exit(1);
    }
    char customerName[100];
    printf("Enter customer name: ");
    scanf("%s", customerName);

    float totalAmount = 0.0;
    int choice;


    do {
        char medicineName[100];
        int quantity;

        printf("Enter medicine name: ");
        scanf("%s", medicineName);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Load data from the medicine file to find the price and update quantity of the selected medicine
        struct Medicine medicine;
        file = fopen("medicine.txt", "r");
        tempFile = fopen("temp.txt", "w"); // Temporary file to store updated medicine quantities
        int medicineFound = 0;

        while (fscanf(file, "%s %f %d", medicine.name, &medicine.price, &medicine.quantity) != EOF) {
            if (strcmp(medicine.name, medicineName) == 0) {
                medicineFound = 1;
                if (medicine.quantity >= quantity) {
                    float amount = medicine.price * quantity;
                    fprintf(billFile, "Customer: %s | Medicine Name: %-30s | Quantity: %d | Price: %.2f | Amount: %.2f\n",customerName, medicineName, quantity, medicine.price, amount);
                    totalAmount += amount;
                    medicine.quantity -= quantity;
                } else {
                    printf("Not enough quantity available for %s\n", medicineName);
                }
            }
            fprintf(tempFile, "%-30s %.2f %d\n", medicine.name, medicine.price, medicine.quantity);
        }
        fclose(file);
        fclose(tempFile);

        if (!medicineFound) {
            printf("Medicine not found.\n");
        }

        printf("Do you want to add more medicines for this customer? (1/0): ");
        scanf("%d", &choice);
    } while (choice != 0);

    if(choice==0){
         remove("medicine.txt");
         rename("temp.txt", "medicine.txt");
    }

    // Display the total amount in the bill
    fprintf(billFile, "Total Amount for %s: %.2f\n", customerName, totalAmount);
    fprintf(billFile, "--------------------------------------------\n");
    printf("Bill generated successfully for %s.\n", customerName);
    fclose(billFile);
}

int main() {

    int choice;
    printf("\t \t \t \t WELCOME TO MEDICAL STORE MANAGEMENT SYSTEM \n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicine\n");
        printf("3. Modify Medicine\n");
        printf("4. Add Customer\n");
        printf("5. Display Customers\n");
        printf("6. Modify Customer\n");
        printf("7. Add Supplier\n");
        printf("8. Display Suppliers\n");
        printf("9. Modify Supplier\n");
        printf("10. Generate Bill for Customer\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicine();
                break;
            case 3:
                modifyMedicine();
                break;
            case 4:
                addCustomer();
                break;
            case 5:
                displayCustomers();
                break;
            case 6:
                modifyCustomer();
                break;
            case 7:
                addSupplier();
                break;
            case 8:
                displaySuppliers();
                break;
            case 9:
                modifySupplier();
                break;
            case 10:
                generateBillForCustomer(billFile);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
