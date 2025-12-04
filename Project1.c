#include <stdio.h>
#include <string.h>

#define MAX 100   // Maximum number of products

// Global arrays to store inventory
char productNames[MAX][50];
int productQuantities[MAX];
float productPrices[MAX];
int productCount = 0;

// Function to add or update a product
void addProduct() {
    char name[50];
    int qty;
    float price;

    printf("Enter Product Name: ");
    scanf("%s", name);

    printf("Enter Quantity: ");
    scanf("%d", &qty);

    printf("Enter Price: ");
    scanf("%f", &price);

    // check if product already exists
    for (int i = 0; i < productCount; i++) {
        if (strcmp(productNames[i], name) == 0) {
            productQuantities[i] += qty;
            printf("Product '%s' updated successfully!\n", name);
            return;
        }
    }

    // new product
    strcpy(productNames[productCount], name);
    productQuantities[productCount] = qty;
    productPrices[productCount] = price;
    productCount++;

    printf("Product '%s' added successfully!\n", name);
}

// Function to view inventory
void viewInventory() {
    if (productCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\n--- Inventory Items ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d. Name: %s | Quantity: %d | Price: %.2f\n",
               i + 1, productNames[i], productQuantities[i], productPrices[i]);
    }
}

// Function to update stock
void updateStock() {
    char name[50];
    int newQty;

    printf("Enter Product Name to update: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(productNames[i], name) == 0) {
            printf("Enter New Quantity: ");
            scanf("%d", &newQty);
            productQuantities[i] = newQty;

            printf("Stock updated successfully!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

// Function to delete a product
void deleteProduct() {
    char name[50];
    printf("Enter Product Name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(productNames[i], name) == 0) {
            // shift elements to delete
            for (int j = i; j < productCount - 1; j++) {
                strcpy(productNames[j], productNames[j + 1]);
                productQuantities[j] = productQuantities[j + 1];
                productPrices[j] = productPrices[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

// Function to search a product
void searchProduct() {
    char name[50];

    printf("Enter Product Name to search: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(productNames[i], name) == 0) {
            printf("Product Found!\n");
            printf("Quantity: %d\n", productQuantities[i]);
            printf("Price: %.2f\n", productPrices[i]);
            return;
        }
    }

    printf("Product not found!\n");
}

// Save inventory to CSV file
void saveToFile() {
    FILE *fp = fopen("inventory.csv", "w");

    if (fp == NULL) {
        printf("Error saving file!\n");
        return;
    }

    // Write header
    fprintf(fp, "Product,Quantity,Price\n");

    // Write product data
    for (int i = 0; i < productCount; i++) {
        fprintf(fp, "%s,%d,%.2f\n", productNames[i], productQuantities[i], productPrices[i]);
    }

    fclose(fp);

    printf("Inventory saved to inventory.csv\n");
    printf("Exiting program...\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Update Stock\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Save & Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            addProduct();
        else if (choice == 2)
            viewInventory();
        else if (choice == 3)
            updateStock();
        else if (choice == 4)
            deleteProduct();
        else if (choice == 5)
            searchProduct();
        else if (choice == 6) {
            saveToFile();
            break;
        } else
            printf("Invalid choice! Try again.\n");
    }

    return 0;
}