#include <stdio.h>
#include <stdlib.h>

#define NULL_PTR 0

struct Node {
    int m_value ;
    Node* m_next ;

    void init( int value ) {
        m_value = value ;
    }

    void dump_value( void ) {
        printf( "Node value: %d\n", m_value ) ;
    }
} ;

struct List {
    Node* m_head ;

    void init( Node* head ) {
        m_head = head ;
    }

    void append( Node* node ) {
        if ( m_head == NULL_PTR ) {
            m_head = node ; // There is not even a node, so assing node to m_head 
            return ;
        }

        Node* current = m_head ; // Start from the first node
        while ( ( current -> m_next ) != NULL_PTR ) {
            current = current -> m_next ; // Iterate until reach a node where its m_next node is null
        }
        current -> m_next = node ; // Assing as the next node for the last in the list
    }

    Node* get_node( int position ) {
        if ( position <= 0 ) {
            return NULL_PTR ; // Position is invalid, so return null
        }

        int count = 1 ;
        Node* current = m_head ;

        while ( current != NULL_PTR && count <= position ) {
            if ( count == position ) {
                return current ; // The node in the position passed
            }
            current = current -> m_next ;
            count++ ;
        }

        return NULL_PTR ; 
    }

    void dump( void ) {
        Node* current = m_head ;
        while ( current != NULL_PTR ) {
            current -> dump_value() ; // Print the node's value
            current = current -> m_next ; // Get the next node
        }
    }

} ;

int main( int argc, char** argv ) {
    /** 
     * In C, the library '<stdlib.h>' function malloc is used to allocate a block of memory on the heap. 
     * The program accesses this block of memory via a pointer that malloc returns. 
     * When the memory is no longer needed, the pointer is passed to free 
     * which deallocates the memory so that it can be used for other purposes.
     * 
     *      void* malloc(size_t size);
     *      void free(void* pointer);
     * 
     * The malloc function is one of the functions in standard C to allocate memory. 
     * Its function prototype is. it is just like a array which allocates size bytes of memory. 
     * If the allocation succeeds, a pointer to the block of memory is returned. 
     * This pointer is guaranteed to be suitably aligned to any type (including struct and such), 
     * otherwise a NULL pointer is returned.
     */

    Node* node_0 = ( Node* ) malloc( sizeof( Node ) ) ;
    node_0 -> m_value = 14 ;

    Node* node_1 = ( Node* ) malloc( sizeof( Node ) ) ;
    node_1 -> m_value = 57 ;

    Node* node_2 = ( Node* ) malloc( sizeof( Node ) ) ;
    node_2 -> m_value = 31 ;

    List* list = ( List* ) malloc( sizeof( List ) ) ;

    list -> append( node_0 ) ;
    list -> append( node_1 ) ;
    list -> append( node_2 ) ;

    list -> dump() ;

    free( list ) ;

    free( node_2 ) ;
    free( node_1 ) ;
    free( node_0 ) ;

    return 0 ;
}