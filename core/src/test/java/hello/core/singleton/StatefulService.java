package hello.core.singleton;

public class StatefulService {
    private int price;   // 상태를 유지하는 필드!!

    //상태로 싱글톤을 설계한 부분
    public void order(String name, int price){
        System.out.println("name = " + name + " price = " + price);
        this.price = price;    //여기가 문제!
    }
    public int getPrice(){
        return price;
    }
}
