package jpabook.jpashop.domain;


import jakarta.persistence.*;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "orders")
@Data
public class Order {

    @Id @GeneratedValue
    @Column(name = "order_id")
    private Long id;


    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "member_id")  //mapping 이름이 member_id 외래키
    private Member member;

    @OneToMany(mappedBy = "order", cascade = CascadeType.ALL)  //한번에 persist해버린다 원래는 엔티티당 해야된다
    private List<OrderItem> orderItems = new ArrayList<>();

    @OneToOne(fetch = FetchType.LAZY, cascade = CascadeType.ALL)
    @JoinColumn(name = "delivery_id")
    private Delivery delivery;

    private LocalDateTime orderDate;   // 주문시간

    @Enumerated(EnumType.STRING)
    private OrderStatus status;   // 주문상태 [ORDER, CANCEL]


    //연관관계 편의메서드  //양방향일떄 써주면 좋다
    public void setMember(Member member){
        this.member = member;
        member.getOrders().add(this);
    }
    public void addOrderItem(OrderItem orderItem){
        orderItems.add(orderItem);
        orderItem.setOrder(this);
    }
    public void setDelivery(Delivery delivery){
        this.delivery = delivery;
        delivery.setOrder(this);
    }


}
