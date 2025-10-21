// Description:
//     This program converts temperatures between Fahrenheit,
//     Celsius, and Kelvin. It also classifies the converted
//     temperature into a category (Freezing, Cold, Comfortable,
//     Hot, Extreme Heat) and provides a simple weather advisory.


#include <stdio.h>
#include <ctype.h> // for toupper()

// Function prototypes
float convertToCelsius(float temp, char scale);
float convertFromCelsius(float tempC, char target);
void categorizeTemperature(float tempC);

int main() {
    float temp, convertedTemp, tempC;
    char original, target;

    // --- Get user input ---
    printf("Enter the temperature value: ");
    scanf("%f", &temp);

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &original);
    original = toupper(original); // Convert to uppercase

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &target);
    target = toupper(target);

    // --- Convert to Celsius first ---
    tempC = convertToCelsius(temp, original);

    // --- Convert from Celsius to target scale ---
    convertedTemp = convertFromCelsius(tempC, target);

    // --- Display result ---
    printf("\nConverted temperature: %.2f %c\n", convertedTemp, target);

    // --- Categorize and provide advisory ---
    categorizeTemperature(tempC);

    return 0;
}

// Convert any scale to Celsius
float convertToCelsius(float temp, char scale) {
    switch (scale) {
        case 'C':
            return temp;
        case 'F':
            return (temp - 32) * 5.0 / 9.0;
        case 'K':
            return temp - 273.15;
        default:
            printf("Invalid input scale. Assuming Celsius.\n");
            return temp;
    }
}

// Convert from Celsius to target scale
float convertFromCelsius(float tempC, char target) {
    switch (target) {
        case 'C':
            return tempC;
        case 'F':
            return (tempC * 9.0 / 5.0) + 32;
        case 'K':
            return tempC + 273.15;
        default:
            printf("Invalid target scale. Returning Celsius.\n");
            return tempC;
    }
}

// Categorize temperature and print advisory
void categorizeTemperature(float tempC) {
    printf("Temperature category: ");

    if (tempC < 0) {
        printf("Freezing\n");
        printf("Weather advisory: Stay indoors and wear heavy clothing!\n");
    } else if (tempC < 10) {
        printf("Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (tempC < 25) {
        printf("Comfortable\n");
        printf("Weather advisory: Enjoy the pleasant weather!\n");
    } else if (tempC < 35) {
        printf("Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Extreme Heat\n");
        printf("Weather advisory: Avoid outdoor activities and stay hydrated!\n");
    }
}