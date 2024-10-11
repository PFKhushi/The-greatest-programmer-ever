def fibonacci(fib: int) -> int:
    if fib < 2:
        return 1
    else:
        return fibonacci(fib - 1) + fibonacci(fib - 2)

def fatorial(fator: int) -> int:
    if fator > 1:
        fator *= fatorial(fator - 1)
    return fator


for i in range(10):
    print(f"Fibonacci({i}) = {fibonacci(i)}")
    

for i in range(6):
    print(f"Fatorial({i}) = {fatorial(i)}")