from scipy.signal import freqs, iirfilter
import matplotlib.pyplot as plt
import numpy as np


if __name__ == '__main__':
    R_BTL = 8
    L = 20e-6
    C_BTL = 0.3e-6
    C_g = 0.05e-6

    R_L = R_BTL / 2

    b = [1]
    a = [(2*C_BTL + C_g) * L, L / R_L, 1]
    w, h = freqs(b, a)
    w = w / (2 * np.pi)
    f_0 = 1 / (2 * np.pi * np.sqrt(L * (2*C_BTL + C_g)))
    print(f'f_0 = {f_0 / 1000:.3f} kHz')
    print(f'Q = {R_L * np.sqrt((2*C_BTL + C_g) / L):4f}')

    plt.semilogx(w, 20 * np.log10(abs(h)))
    plt.xlabel('Frequency (Hz)')
    plt.ylabel('Amplitude response [dB]')
    plt.axvline(x=f_0, linestyle='--', color='r')
    plt.grid(True)
    plt.show()
