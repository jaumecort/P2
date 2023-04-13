from scipy.io.wavfile import read
import matplotlib.pyplot as plt
plt.rcParams["figure.figsize"] = [7.50, 3.50]
plt.rcParams["figure.autolayout"] = True
input_data = read("prueba.wav")
audio = input_data[1]
input_data_s = read("prueba_silenced.wav")
audio_s = input_data_s[1]
fig, (ax1, ax2) = plt.subplots(2)
ax1.plot(audio[0:1024000])
ax2.plot(audio_s[0:1024000])
plt.show()