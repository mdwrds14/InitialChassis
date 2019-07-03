import re

filename = "./src/main.cpp"

# Read in the file
f = open(filename,'r')
filedata = f.read()
f.close()

# Replace the target string
n = re.sub(r"(?i)^.*#define VERSION_NUMBER (\d+)", lambda (digit): "#define VERSION_NUMBER " + str(1 + int(digit.group(1))), filedata, flags=re.MULTILINE)


# Write the file out again
f = open(filename, 'w')
f.write(n)
f.close()

