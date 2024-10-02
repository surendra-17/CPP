### To add SSH keys to two different GitHub accounts, you'll need to generate separate SSH keys for each account and configure your SSH client to use the correct key for each account. Here’s how to do it step by step:

## Step 1: Generate SSH Keys
-   Open your terminal.

-   Generate SSH keys for your first GitHub account (personal):

        ssh-keygen -t rsa -b 4096 -C "your_personal_email@example.com"

    When prompted, save the key with a specific name:

        /home/your_username/.ssh/id_rsa_personal

## Step 2: Add SSH Keys to the SSH Agent
- Start the SSH agent:

        eval "$(ssh-agent -s)"
- Add both SSH keys to the agent:

        ssh-add ~/.ssh/id_rsa_personal

## Step 3: Configure SSH
Create or edit the SSH config file to specify which key to use for each GitHub account.

- Open (or create) the config file:

        nano ~/.ssh/config
- Add the following configuration:

        # Personal account
        Host github.com-personal
            HostName github.com
            User git
            IdentityFile ~/.ssh/id_rsa_personal

## Step 4: Add SSH Keys to GitHub Accounts

- Copy the SSH public key:

        cat ~/.ssh/id_rsa_personal.pub

- Go to GitHub:

    1. Sign in to your personal GitHub account.

    2. Navigate to Settings > SSH and GPG keys > New SSH key.

    3. Paste the copied public key and give it a title. Save it.
## Step 5: Clone Repositories with Specific Accounts
When cloning repositories, use the defined hosts from your SSH config.

        git clone git@github.com-personal:username/repo.git

## Step 6 (Optional): Adding SSH keys to existing repository

### Step 1: Check the Current Remote URL

1. Open your terminal.

2. Navigate to the repository directory:

        cd /path/to/your/repo
3. Check the current remote URL:

        git remote -v

    You should see output similar to this, indicating it’s using HTTPS:

        origin  https://github.com/username/repo.git (fetch)
        origin  https://github.com/username/repo.git (push)

### Step 2: Change the Remote URL to Use SSH

1. Change the remote URL to the SSH format. Use the following command, replacing username and repo with your GitHub username and the repository name:

        git remote set-url origin git@github.com:username/repo.git
2. Verify that the remote URL has been updated:

        git remote -v
    The output should now reflect the SSH URL:

        origin  git@github.com:username/repo.git (fetch)
        origin  git@github.com:username/repo.git (push)

### Step 3: Test the SSH Connection

To ensure everything is set up correctly, test your SSH connection:

    ssh -T git@github.com
You should see a message like:

    Hi username! You've successfully authenticated, but GitHub does not provide shell access.



