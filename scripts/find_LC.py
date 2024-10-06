import math


if __name__ == '__main__':
    f_0 = 40e+3
    R_BTL = 4

    R_L = R_BTL / 2
    L = math.sqrt(2) * R_L / (2 * math.pi * f_0)
    C = 1 / (2 * math.pi * f_0 * R_L * math.sqrt(2))

    C_BTL = C / 2.2
    C_g = 2 * C_BTL / 10

    print(f"L = {(10 ** 6) * L:.3f}μH")
    print(f"C_BTL = {(10 ** 6) * C_BTL:.3f}μF")
    print(f"C_g = {(10 ** 6) * C_g:.3f}μF")
