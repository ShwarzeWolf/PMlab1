import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.stats

url = "C://Users//1358365//PycharmProjects//PMlab1//input.txt"
rawData = []
with open(url) as file:
    for line in file:
        rawData.append([int(x) for x in line.split(" ")])

data = np.array(rawData)
data.sort()
data = data.reshape((100, 1))

counts, bin_edges = np.histogram(data)
cdf = np.cumsum(counts)
plt.plot(bin_edges[1:], cdf)
plt.xlabel('Value')
plt.savefig("C://Users//1358365//PycharmProjects//PMlab1//cdf.png")
plt.clf()

_, ax = plt.subplots()
ax.hist(data, 40, color = '#539caf')
ax.set_xlabel("Value")
ax.set_ylabel("frequency")
ax.set_title("histogram")
plt.savefig("C://Users//1358365//PycharmProjects//PMlab1//hist.png")
plt.clf()

#ящик с усами
_, ax = plt.subplots()
ax.boxplot(data, patch_artist = True)
ax.set_ylabel("results")
ax.set_xlabel("Values")
ax.set_title("whiskersPlot")
plt.savefig("C://Users//1358365//PycharmProjects//PMlab1//whiskers.png")