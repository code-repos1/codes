#!/bin/bash
# Author: Karlson
# Email: kohkarlson@gmail.com
# This script creates a new user and adds them to a particular group

echo "Hello and Welcome. This script creates a user account, then adds the user to a particular group"

# Create User

# Prompt for username
while true; do
    read -p "Enter username: " username

    if id "$username" >/dev/null 2>&1; then
        echo "User $username already exists. Please enter another username."
    else
        break
    fi
done

read -s -p "Enter password: " password
echo # Prompt for password

# Create user with provided username
sudo useradd -m "$username"

# Set password for the new user
echo "$username:$password" | sudo chpasswd

echo "User $username created successfully."


# Add User to Group

# Ask the user if they want to join a group
read -p "Do you want to join a group? (y/n): " join_group

if [[ $join_group == "y" || $join_group == "Y" ]]; then
    # Ask the user to enter group(s)
    read -p "Enter group(s) to be added: " group

    # Check if the group exists
    if grep -q "^$group:" /etc/group; then
        sleep 1
        echo "Group $group exists."
    else
        echo "Group $group does not exist. Creating the group..."
        sleep 1
        groupadd $group
    fi

    # Add the user to the group
    usermod -a -G "$group" "$username"

    # Show all the groups that the user is in and their permissions
    echo "Group created. Here are the group(s) that you're in and their permission(s):"
    groups "$username"
else
    echo "User $username has not been added to any group. Exiting..."
fi





<<comment

Explanation
===========
```bash
#!/bin/bash
# Author: Karlson
# Email: kohkarlson@gmail.com
# This script creates a new user and adds them to a particular group

echo "Hello and Welcome. This script adds a user to a particular group"
```

- This line specifies the interpreter to use (`bash`) for executing the script.
- The following lines are comments that provide information about the script's author and purpose.

```bash
while true; do
    read -p "Enter username: " username

    if id "$username" >/dev/null 2>&1; then
        echo "User $username already exists. Please enter another username."
    else
        break
    fi
done
```

- This sets up a loop that continues until a unique username is entered.
- The `read` command prompts the user to enter a username and stores it in the `username` variable.
- The `if` statement checks if the entered username already exists. If it does, it displays a message asking the user to enter another username.
- If the username is unique (i.e., it doesn't exist), the `break` statement exits the loop.

```bash
read -s -p "Enter password: " password
echo # Prompt for password

sudo useradd -m "$username"
echo "$username:$password" | sudo chpasswd

echo "User $username created successfully."
```

- The `read` command prompts the user to enter a password without displaying it on the screen and stores it in the `password` variable.
- The `echo` command is used to provide a visual prompt by printing an empty line.
- The `sudo useradd -m "$username"` command creates a new user with the entered username and the `-m` option creates a home directory for the user.
- The `echo "$username:$password" | sudo chpasswd` command sets the password for the newly created user.
- The final `echo` statement displays a success message indicating that the user has been created.

```bash
read -p "Do you want to join a group? (y/n): " join_group

if [[ $join_group == "y" || $join_group == "Y" ]]; then
    read -p "Enter group(s) to be added: " group

    if grep -q "^$group:" /etc/group; then
        sleep 1
        echo "Group $group exists."
    else
        echo "Group $group does not exist. Creating the group..."
        sleep 1
        groupadd $group
    fi

    usermod -a -G "$group" "$username"

    echo "Group created. Here are the group(s) that you're in and their permission(s):"
    groups "$username"
else
    echo "User $username has not been added to any group. Exiting..."
fi
```

- The `read` command prompts the user to enter whether they want to join a group by entering 'y' or 'n', and stores the response in the `join_group` variable.
- The `if` statement checks if the user wants to join a group.
- If the response is 'y' or 'Y', the script proceeds with the group adding section.
- The `read` command prompts the user to enter the group(s) they want to add the user to and stores it in the `group` variable.
- The `if` statement checks if the entered group already exists in the `/etc/group` file using the `grep` command.
- If the group exists, it displays a message indicating its existence. Otherwise, it creates the group using `groupadd`.
- The `usermod -a -G "$group" "$username"` command adds the user to the group(s) specified by appending the group(s) to the user's existing groups.
- The final `echo` statement displays a message indicating that the group has been created and lists the groups the user is a member of using the `groups` command.
- If the user chose not to join a group, the script displays a message indicating that the user has not been added to any group and exits.

comment
