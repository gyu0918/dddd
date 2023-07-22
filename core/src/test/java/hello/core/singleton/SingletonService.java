package hello.core.singleton;

public class SingletonService {

    private static final SingletonService instance = new SingletonService();

    public static SingletonService getInstance(){
        return instance;
    }

    private SingletonService(){              //private 생성자를 만들어준다 => new SingletonService를 중복해서 하는걸 막기 위해
    }

    public void logic(){
        System.out.println("싱글톤 객체 로직 호출");
    }
}
