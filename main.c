#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Song Node
struct node {
    char song[50];
    struct node *next;
};

struct node *head = NULL;

// Add Song
void addSong() {
    struct node *newNode, *temp;
    
    newNode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter song name: ");
    scanf(" %[^\n]", newNode->song);
    
    newNode->next = NULL;
    
    if(head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    printf("Song added successfully!\n");
}

// Display Playlist
void display() {
    struct node *temp;
    
    if(head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    
    temp = head;
    printf("\nPlaylist:\n");
    
    while(temp != NULL) {
        printf("%s -> ", temp->song);
        temp = temp->next;
    }
    
    printf("NULL\n");
}

// Delete Song
void deleteSong() {
    struct node *temp, *prev;
    char name[50];
    
    printf("Enter song name to delete: ");
    scanf(" %[^\n]", name);
    
    temp = head;
    
    // Delete first node
    if(temp != NULL && strcmp(temp->song, name) == 0) {
        head = temp->next;
        free(temp);
        printf("Song deleted!\n");
        return;
    }
    
    // Search for song
    while(temp != NULL && strcmp(temp->song, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL) {
        printf("Song not found!\n");
        return;
    }
    
    prev->next = temp->next;
    free(temp);
    
    printf("Song deleted successfully!\n");
}

// Main Function
int main() {
    int choice;
    
    while(1) {
        printf("\n--- Music Playlist Menu ---\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addSong();
                break;
                
            case 2:
                deleteSong();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                exit(0);
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
