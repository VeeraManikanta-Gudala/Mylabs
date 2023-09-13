package JavaPrograms;


class Q{
    int item;
    boolean itemsinq;
    synchronized void produce(int item){
        if(itemsinq){
            try{
                wait();
            }
            catch(InterruptedException ie){
                System.out.println(ie);
            }
        }
        this.item = item;
        itemsinq = true;
        System.out.println("produced item is :" + item);
        notify(); 
    }
    synchronized void consume(){
        if(itemsinq){
            try {
                wait();
            } catch (InterruptedException ie) {
                System.out.println(ie);
                // TODO: handle exception
            }
        }
        System.out.println("consumed item:" + item);
        itemsinq = false;
        notify();
    }

}
class Producer implements Runnable{
    Q q;
    Producer(Q q){
        this.q = q;
        new Thread(this).start();
    }
    public void run(){
        int i = 1;
        while(i<=5){
            q.produce(i);
        }
    }
}

class Consumer implements Runnable{
    Q q;
    Consumer(Q q){
        this.q = q;
        new Thread(this).start();
    }
    public void run(){
        int i = 1;
        while(i<+ 5){
            q.consume();
            i++;
        }
    }
}
public class Prodcons{
   public static void main(String[] args){
         Q q1 = new Q();
         new Producer(q1);
         new Consumer(q1);
   }
    
}

