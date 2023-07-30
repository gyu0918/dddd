package haha.gogo;



import lombok.Getter;
import lombok.Setter;

import javax.swing.*;

@Getter
@Setter
public class HelloLombok {
    private int age;
    private String name;

    public static void main(String[] args) {
       HelloLombok helloLombok = new HelloLombok();
       helloLombok.setName("dddd");

       String name = helloLombok.getName();
       System.out.println("name = " + name);
    }
}
