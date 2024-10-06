from scipy.signal import freqs, iirfilter
import matplotlib.pyplot as plt
import numpy as np


if __name__ == '__main__':
    R_BTL = 4
    L = 10e-6
    C_BTL = 0.63e-6
    C_g = 0.12e-6

    R_L = R_BTL / 2

    b = [1]
    a = [1, L / R_L, 2 * L * C_BTL + C_g + 1]
    w, h = freqs(b, a, worN=np.logspace(-1, 5, 5000))
    w = w / (2 * np.pi)

    plt.semilogx(w, 20 * np.log10(abs(h)))
    plt.xlabel('Frequency (Hz)')
    plt.ylabel('Amplitude response [dB]')
    plt.grid(True)
    plt.show()
