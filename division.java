import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
class divi extends JFrame implements ActionListener{
    JTextField t1,t2,t3;
    JLabel l1,l2,l3;
    JButton b1;
    JPanel p;
    divi(){
        setTitle("division");
        p=new JPanel(new GridLayout(3,2));
        l1=new JLabel("num1:");
        t1=new JTextField(10);
        l2=new JLabel("num2:");
        t2=new JTextField(10);
        l3=new JLabel("result:");
        t3=new JTextField(10);
        b1=new JButton("divide");
        b1.addActionListener(this);
        Font f=new Font("seoge UI",Font.PLAIN,22);
        p.setFont(f);
        p.setBackground(Color.pink);
        add(p);
        p.add(l1);p.add(t1);p.add(l2);p.add(t2);p.add(l3);p.add(t3);add(b1,BorderLayout.SOUTH);
        setSize(300,300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

    }
    public void actionPerformed(ActionEvent e){
        if(e.getSource()==b1){
            try{
                int a=Integer.parseInt(t1.getText());
                int b=Integer.parseInt(t2.getText());
                int c;
                c=a/b;
                t3.setText(""+c);
            }
            catch(NumberFormatException ex){
                t3.setText("-");
                JOptionPane.showMessageDialog(this,"number format");
            }
           catch(ArithmeticException ex){
                t3.setText("-");
                JOptionPane.showMessageDialog(this,"arithmetic format");
            } 
            catch(Exception ex){
                t3.setText("-");
                JOptionPane.showMessageDialog(this,"exception");
            }
            }

        }
    }
class division{
    public static void main(String[] args){
        new divi();
    }
}