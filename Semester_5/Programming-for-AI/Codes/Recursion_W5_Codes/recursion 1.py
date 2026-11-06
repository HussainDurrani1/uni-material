def countdown(n):
    # 1. Base Case
    if n <= 0:
        print("Liftoff!")
        return

    # 2. Pre-recursive action (winding)
    print(f"Pushing frame: {n}")

    # 3. Recursive call with a strictly smaller sub-problem
    countdown(n - 1)

    # 4. Post-recursive action (unwinding)
    print(f"Popping frame: {n}")

countdown(3)