class Program
{
    public static void Main(String[] args)
    {
        HashTable ht = new HashTable(20);
        ht.put("a", 4);
        ht.put("b", 5);
        ht.putToElem("c",3,"a");
        ht.putToElem("d",6,"c");
        ht.putToElem("e",2,"a");
        ht.putToElem("f",1,"c");
        
        ht.print();
        Console.WriteLine();
        ht.sortNodes();
        Console.WriteLine();
        ht.print();
    }


    class Node
    {
        private string K;
        private int V;
        private Node Next;
        private int size_c;
        private Node[] arr;

        public Node()
        {
            this.K = "";
            this.V = 0;
            this.Next = null;
            this.size_c = 0;
            this.arr = new Node[size_c+1];
        }
        public Node(String K, int V)
        {
            this.K = K;
            this.V = V;
            this.Next = null;
            this.size_c = 0;
            this.arr = new Node[size_c + 1];
        }
        
        public void setNext(Node Next)
        {
            this.Next = Next;
        }

        public void print()
        {
            Console.WriteLine(this.K + " : " + this.V);
            if(size_c > 1  ) Console.WriteLine("==========");
            for(int i = 0; i < size_c; i++)
            {
                Console.Write("\t");
                arr[i].print();
            }

            if (size_c > 1) Console.WriteLine("----------");
        }

        public Node getNext()
        {
            return Next;
        }
        public String getK() => K;
        public int getV() => V;
        public int getSize() => size_c;
        public Node[] getArr() => arr;

        public void push(String K, int V)
        {
            // recreate array
            Node[] temp = new Node[size_c + 1];
            for (int i = 0; i < size_c; i++)
            {
                temp[i] = arr[i];
            }
            arr = new Node[size_c + 1];
            for (int i = 0; i < size_c; i++)
            {
                arr[i] = temp[i];
            }
            arr[size_c] = new Node(K,V);
            size_c++;
            
            
        }

        public void SortNodes()
        {
            
            // sort array using buble sort
            for(int i = 0; i < size_c; i++)
            {
                this.arr[i].SortNodes();
                for(int j = 0; j < size_c - 1 - i; j++)
                {
                    if (arr[j].getV() > arr[j + 1].getV())
                    {
                        Node temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
    }

    class LinkedList
    {
        private Node Head;
        private int size;

        public LinkedList()
        {
            this.Head = null;
            this.size = 0;
        }

        public void push(String K, int V)
        {
            Node newNode = new Node(K,V);
            if (this.Head == null)
            {
                this.Head = newNode;
            }
            else
            {
                newNode.setNext(Head);
                Head = newNode;
            }

            size++;
        }
        
        public void print()
        {
            Node temp = Head;
            while (temp != null)
            {
                temp.print();
                temp = temp.getNext();
            }
        }
        public Node getHead()
        {
            return Head;
        }
        public int getSize() => size;
        //sort nodes in list
        public void sort()
        {
            Node temp = Head;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size - 1 - i; j++)
                {
                    if (temp.getV() > temp.getNext().getV())
                    {
                        Node temp1 = temp;
                        temp = temp.getNext();
                        temp.setNext(temp1);
                    }
                    temp = temp.getNext();
                }
            }
        }
    }

    class HashTable
    {
        private LinkedList[] table;
        private int size;
    
        public HashTable()
        {
            this.size = 10; 
            this.table = new LinkedList[size];
            for (int i = 0; i < size; i++)
            {
                table[i] = new LinkedList();
            }
        }
    
        public HashTable(int size)
        {
            this.size = size;
            this.table = new LinkedList[size];
            for (int i = 0; i < size; i++)
            {
                table[i] = new LinkedList(); 
            }
        }
    
        private int hash(String key)
        {
            int hash = 0;
            for (int i = 0; i < key.Length; i++)
            {
                hash += key[i];
            }
            return hash % size;
        }

        public void put(String key, int value)
        {
            int hash = this.hash(key);
            if (table[hash] == null) {
                table[hash] = new LinkedList();
            }
            table[hash].push(key, value);
        }

        public void putToElem(String K, int V, String K_p)
        {
            Node parent = getNode(K_p);
            if (parent == null) return;
            parent.push(K,V);
        }

        public Node getNode(String K)
        {
            Node res = null;
            for (int i = 0; i < size; i++)
            {
                if (table[i] != null)
                {
                    Node curr = table[i].getHead();
                    for (int j = 0; j < table[i].getSize(); j++)
                    {
                        res = get(curr, K);
                        if (res.getK() == K) return res;
                        curr = curr.getNext();
                    }
                }
                
            }

            return res;
        }

        private Node get(Node node, String K)
        {
            if (node.getK() == null) return null;
            if(node.getK() == K) return node;
            for (int i = 0; i < node.getSize(); i++)
            {
                Node res = get(node.getArr()[i], K);
                if (res.getK() == K) return res;
            }
            return node;
        }
        public void print()
        {
            for (int i = 0; i < size; i++)
            {
                if (table[i] != null) {
                    table[i].print();
                }
            }
        }

        public void print(String K)
        {
            getNode(K).print();
        }

        public void sortNodes()
        {
            for (int i = 0; i < size; i++)
            {
                if (table[i].getHead() != null)
                {
                    table[i].sort();
                    Node temp = table[i].getHead();
                    for (int j = 0; j < table[i].getSize(); j++)
                    {
                        temp.SortNodes();
                        temp=temp.getNext();
                    }
                }
            }   
        }
        
        
        
    }

}