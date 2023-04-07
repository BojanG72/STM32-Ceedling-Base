FROM ubuntu:latest

# Update package index and install required packages
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential \
    gcc-arm-none-eabi \
    git \
    ruby \
    ruby-dev \
    make \
    && rm -rf /var/lib/apt/lists/*

# Install Ceedling
RUN gem install ceedling

# Set environment variables
ENV PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/opt/gcc-arm-none-eabi-9-2020-q2-update/bin"

# Set the working directory to /app
WORKDIR /app

# Copy the application code to the container image
COPY . .

# Build the application
RUN ceedling test:all

# Start the application
CMD [ "bash" ]
