def find_largest_number(numbers):
    if len(numbers) == 0:
        raise Exception("The list is empty!")

    largest = numbers[0]
    for num in numbers:
        if num > largest:
            largest = num
    return largest

try:
    # Ask user to enter numbers
    user_input = input("Enter numbers separated by spaces: ")

    # Convert the input into a list of integers
    number_list = user_input.split()
    number_list = [int(x) for x in number_list]

    # Call the function
    largest = find_largest_number(number_list)
    print("The largest number is:", largest)

except Exception as e:
    print("Error:", e)
