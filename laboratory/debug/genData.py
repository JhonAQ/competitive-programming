import csv
import random

def generate_random_numbers(start, end, count, include_limits, filename='data.csv'):
    if not include_limits:
        start += 1
        end -= 1

    numbers = [random.randint(start, end) for _ in range(count)]

    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        for number in numbers:
            writer.writerow([number])

if __name__ == "__main__":
    start = int(input("Ingrese el número de inicio: "))
    end = int(input("Ingrese el número final: "))
    count = int(input("Ingrese la cantidad de datos a generar: "))
    include_limits = input("¿Incluir límites? (sí/no): ").strip().lower() == 'sí'
    
    generate_random_numbers(start, end, count, include_limits)
    print(f"Se han generado {count} números aleatorios y guardado en 'data.csv'.")
